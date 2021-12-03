#!/usr/bin/env python

from task import Task
from component import Component
from app import Application
from cluster import Cluster
from scheduler import Scheduler
from simulator import Simulator
from parseconfig import Parsing
from plotter import Plotter

import matplotlib.pyplot as plt
import pandas as pd

import sys
import numpy as np
import copy
import time

#hardcode simple DAG for testing 
#    t0
#    /\
#0.5/  \2.5
#  t1   t2
#   \   /
#0.75\ /1
#     t3

edges = ({},{0:0.003},{0:0.006},{1:0.002,2:0.003})
tasks = [0,1,2,3]

#
#edges = ({},{0:2},{0:4.5},{1:1.5,2:0},{})
#tasks = [0,1,2,3,4]


power = {0:{0:1.1, 1:1.7012423, 2:0.01}, 1:{0:2.2, 1:1.9807628, 2:0.02}, 2:{0:3.0, 1:1.7012423, 2:0.05}, 3:{0:2.2, 1:2.0810245, 2:0.04}}
WCET = {0:{0:0.3, 1:0.028, 2:7.0}, 1:{0:0.1, 1:0.1, 2:7.2}, 2:{0:0.2, 1:0.028, 2:4.5}, 3:{0:0.2, 1:0.08, 2:7.9}}


A = Application(tasks, edges, WCET, power, 100000)
print("alltasks: ", A.alltasks)


#parsing floorplan to opbtain the components
P = Parsing("matex.config","multicore.flp")
flp = P.parsefloorplan()

print("flp size:",len(flp))
#create cluster and add components
clus = Cluster()
for i,unit in enumerate(flp):
	clus.add_component(Component(i, 1, (unit[3],unit[4]),unit[1],unit[2]))


print("cluster: ")
for comp in clus._clus:
	print(comp)
	
print("clus end")
#sys.exit()

##hardcode component for testing
#c0 = Component(0, 0, (0,0))
#c1 = Component(1, 1, (0,1))
#c2 = Component(2, 2, (1,0))

#clus = Cluster()
#clus.add_component(c0)
#clus.add_component(c1)
#clus.add_component(c2)

#ageing_interval = np.arange(0.0005,0.1,0.005)
#ageing_interval = np.arange(0.0005,0.03,0.01)	#aging interval in seconds
#ageing_interval = np.arange(0.0005,0.1,0.01)	#aging interval in seconds
#ageing_interval = np.array([0.0105,0.0055, 0.0005])
#ageing_interval = np.array([0.0038,0.0020])
ageing_interval = np.array([0.0005])#,0.0020,0.0038,0.0055, 0.0105, 0.0205,0.0305,0.0405,0.0505,0.0605,0.0705,0.0805,0.0905])
pow_interval = np.arange(1,20)		#power interval in number of samples
pow_int = 1
itter = 20#np.arange(5,60,10)#10 #20
ageing_int = 0.0105
n=1#30

MTTF = []
ET = []
X_axis = []
TTF_all={}
FFT_all={}
ET_all={}
j=0
for ageing_int in ageing_interval:
#	X_axis.append(pow_int*0.0001)
	X_axis.append(ageing_int)
	print("ittr:",ageing_int)
	TTF = np.zeros(n)
	firstfail = np.zeros(n)
	firstfail_time = np.zeros(n)
	et = np.zeros(n)
	
	for i in range(n):
		print("itteration:",i)
		cluster = copy.deepcopy(clus)
		app = copy.deepcopy(A)
		sim =  Simulator(app,cluster,"ETF",ageing_int,pow_int,itter)
		t_start = time.perf_counter()  
		firstfail_time[i],firstfail[i],TTF[i] = sim.run()
		t_stop = time.perf_counter()
		et[i] = t_stop-t_start
#		print("FF:",firstfail_time[i],"SF:",TTF[i])
	
	ET_all["INT{}".format(j)]=et
	TTF_all["TTF{}".format(j)]=TTF
	FFT_all["FFT{}".format(j)]=firstfail_time
	
#	plt.plot(firstfail,TFF,'x')
#	plt.show()
	unique, counts = np.unique(firstfail, return_counts=True)
	print(dict(zip(unique, counts)))
	


#	plt.hist(TTF, density=True, bins=10)
#	plt.show()
	
	MTTF.append(np.average(TTF))
	ET.append(t_stop-t_start)
	print("TTF:",TTF,"\nMTTF:",np.average(TTF), "Execution time:",t_stop-t_start)

	j+=1


df = pd.DataFrame(data=ET_all)
df.to_csv("../results/et.csv")


#ttfdata = {'ttf0':TTF_all[0],'fft0:':FFT_all[0],'ttf1':TTF_all[1],'fft1:':FFT_all[1],'ttf2':TTF_all[2],'fft2:':FFT_all[2]}
df = pd.DataFrame(data=TTF_all)
df.to_csv("../results/ttf.csv")

df = pd.DataFrame(data=FFT_all)
df.to_csv("../results/fft.csv")



#data = {'age_int':X_axis,'MTTF': MTTF, 'ET':ET }
#df = pd.DataFrame(data=data)
#df.to_csv("age_MTTF_ET_hr.csv")

#plt.plot(X_axis,MTTF)
#plt.xlabel('Interval')
#plt.ylabel('MTTF')
#plt.show()

#plt.plot(X_axis,ET)
#plt.xlabel('Interval')
#plt.ylabel('Execution Time')
#plt.show()









#print("\n\n", clus)

#S = Scheduler(A,clus)


#go = S.MET()
#print("final res:",go)
#for c in clus.components:
#	print("component:",c.ID)
#	print (c.assigned_tasks)
#	
#	
#print("-----------")
#go = S.ETF()
#print("-----------")
#print("final res:",go)
#for c in clus.components:
#	print("component:",c.ID)
#	print (c.assigned_tasks)



