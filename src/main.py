#!/usr/bin/env python

from task import Task
from component import Component
from app import Application
from cluster import Cluster
from scheduler import Scheduler
from simulator import Simulator
from parseconfig import Parsing
from plotter import Plotter
from multiprocessing import Pool, cpu_count


import matplotlib.pyplot as plt
import pandas as pd

import sys
import numpy as np
import copy
import time

shed_policy = "MET"

def simulation (clus,App,ageing_int,pow_int,itter,i):
	print("\n:::::::::::::::::::::::itteration ",i," ::::::::::::::::::::::")
	np.random.seed() #re-seed random generator
	cluster = copy.deepcopy(clus)
	app = copy.deepcopy(App)
	app.calc_energy(cluster)
	sim =  Simulator(app,cluster,shed_policy,ageing_int,pow_int,itter,i)
	
	
#	t_start = time.perf_counter()  
	firstfail_time,firstfail,TTF,idle,temp = sim.run()
#	firstfail_time,firstfail,TTF,idle = sim.run()
#	print("here!")
#	sys.exit()
#	t_stop = time.perf_counter()
#	temp_all.append(temp)
#	et[i] = t_stop-t_start
	
	return TTF,idle,temp





#hardcode simple DAG for testing 
#    t0 -------
#    /\        \
#0.5/  \2.5     \
#  t1   t2      t4
#   \   /      /  \
#0.75\ /1     /    \
#     t3     t5     t6
#edges = ({},{0:0.003},{0:0.006},{1:0.002,2:0.003},{0:0.003},{4:0.003},{4:0.004})
#tasks = [0,1,2,3,4,5,6]


###DAG-2
#          t0
#          |
#  ---------------------
#  |     |      |      |
#  t1    t2     t3     t4
#  |     |      |      |
#  ---------------------
#          |  
#          t5

edges = ({},{0:0.003},{0:0.006},{0:0.003},{0:0.005},{1:0.002,2:0.003,3:0.005,4:0.002})
tasks = [0,1,2,3,4,5]


#edges = ({},{0:0.003},{0:0.006},{1:0.002,2:0.003})
#tasks = [0,1,2,3]

#
#edges = ({},{0:2},{0:4.5},{1:1.5,2:0},{})
#tasks = [0,1,2,3,4]


power = {0:{0:1.1, 1:1.7012423, 2:0.01}, 1:{0:2.2, 1:1.9807628, 2:0.02}, 2:{0:3.0, 1:1.7012423, 2:0.05}, 3:{0:2.2, 1:2.0810245, 2:0.04},4:{0:2.2, 1:2.0810245, 2:0.04},5:{0:2.2, 1:2.0810245, 2:0.04},6:{0:2.2, 1:2.0810245, 2:0.04}}
#WCET = {0:{0:0.3, 1:0.028, 2:7.0}, 1:{0:0.1, 1:0.1, 2:7.2}, 2:{0:0.2, 1:0.028, 2:4.5}, 3:{0:0.2, 1:0.08, 2:7.9},4:{0:0.2, 1:0.08, 2:7.9},5:{0:0.2, 1:0.08, 2:7.9},6:{0:0.2, 1:0.08, 2:7.9}}

WCET = {0:{0:[1.051,0.540,0.375,0.288],1:[1.051,0.540,0.375,0.288],2:[1.051,0.540,0.375,0.288],3:[1.051,0.540,0.375,0.288]},1:{0:[1.051,0.540,0.375,0.288],1:[1.051,0.540,0.375,0.288],2:[1.051,0.540,0.375,0.288],3:[1.051,0.540,0.375,0.288]},2:{0:[1.051,0.540,0.375,0.288],1:[1.051,0.540,0.375,0.288],2:[1.051,0.540,0.375,0.288],3:[1.051,0.540,0.375,0.288]},3:{0:[1.051,0.540,0.375,0.288],1:[1.051,0.540,0.375,0.288],2:[1.051,0.540,0.375,0.288],3:[1.051,0.540,0.375,0.288]},4:{0:[1.051,0.540,0.375,0.288],1:[1.051,0.540,0.375,0.288],2:[1.051,0.540,0.375,0.288],3:[1.051,0.540,0.375,0.288]},5:{0:[1.051,0.540,0.375,0.288],1:[1.051,0.540,0.375,0.288],2:[1.051,0.540,0.375,0.8],3:[1.051,0.540,0.375,0.288]}}

#WCET = {0:{1:[1.051,0.540,0.375,0.288]},1:{1:[1.051,0.540,0.375,0.15]},2:{1:[1.051,0.540,0.375,0.1]},3:{1:[1.051,0.540,0.375,0.1]},4:{1:[1.051,0.540,0.375,0.4]},5:{1:[1.051,0.540,0.375,0.288]}}


A = Application(tasks, edges, WCET, power, 1.8)

#print("alltasks: ", A.alltasks)


#parsing floorplan to opbtain the components
P = Parsing("matex.config","multicore_3x3.flp")
flp = P.parsefloorplan()

print("flp size:",len(flp))

grid_size=9
#idle_power = 0.872341  #0.872385338112
idle_power = [0.272063,0.435726,0.649266,0.917593]
dvfs_levels = {0:1,1:2,2:3,3:4} #GHz
all_clus = []

#create cluster and add components
#clus = Cluster()
#for i,unit in enumerate(flp):
#	clus.add_component(Component(i, 1, unit[0],(unit[3],unit[4]),unit[1],unit[2]))
#	if i>0:
#		cl = copy.deepcopy(clus)
#		all_clus.append(cl)

for i in range (1,grid_size):
	enabled_comp = np.zeros(grid_size,dtype=bool)
	cl = Cluster()
	for j,unit in enumerate(flp[0:i+1]):
		cl.add_component(Component(j, 2, unit[0],(unit[3],unit[4]),unit[1],unit[2],idle_power,dvfs_levels))


#	cl = copy.deepcopy(clus)
	enabled_comp[0:i+1] = True
	cl.enabled_comp = enabled_comp
#	print("ec:",cl.enabled_comp)
	all_clus.append(cl)
	



#sys.exit()




#print("cluster: ")
#for clstr in all_clus:
#	print("\n:::set:::\n")
#	for comp in clstr._clus:
#		print(comp)
#	
#print("clus end")
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
ageing_interval = np.array([0.0038])
#ageing_interval = np.array([0.0005,0.0020,0.0038,0.0055, 0.0105, 0.0205,0.0305,0.0405,0.0505,0.0605,0.0705,0.0805,0.0905])
pow_interval = np.arange(1,10)		#power interval in number of samples
#pow_int = [1,2,3,4,5,6,7,8,9,10]
pow_int=20
itter = 20  #np.arange(5,60,10)#10 #20
#ageing_int = 0.0105
n=10
ageing_int = 0.0205

MTTF = []
ET = []
X_axis = []
TTF_all={}
FFT_all={}
ET_all={}
temp_all=[]
allf_temp_all=[]
j=1
et = np.zeros(len(all_clus))
all_the_temp = []
for clus in all_clus[:1]:
#	X_axis.append(pow_int*0.0001)
	X_axis.append(ageing_int)
	print("no of comp:",j+2)
#	print("\nno of comp:", len(clus._clus))
	TTF = np.zeros(n)
	firstfail = np.zeros(n)
	firstfail_time = np.zeros(n)
	
	idle=np.zeros(n)
#	temp_all = []
	
	tik = time.perf_counter() 
	data_ip = []
	for i in range(n):

		data_ip.append((clus,A,ageing_int,pow_int,itter,i))
	
#		cluster = copy.deepcopy(all_clus[0])
#		app = copy.deepcopy(A)
#		sim =  Simulator(app,cluster,"ETF",ageing_int,pow_int,itter,i)
#		
#		
#		t_start = time.perf_counter()  
#		firstfail_time[i],firstfail[i],TTF[i],idle[i],temp = sim.run()
#		t_stop = time.perf_counter()
#		temp_all.append(temp)
#		et[i] = t_stop-t_start

	
	with Pool() as pool:
		rslt = pool.starmap(simulation,data_ip)
		
#	print("@@@@@@HERE!@@@@@@@@")
	tok = time.perf_counter() 
	et[j] = tok-tik
	for i,t in enumerate(rslt):
		TTF[i] = t[0]
		firstfail_time[i] = t[1]
#		print("results:",len(t))
#	sys.exit()
#	results = np.array(rslt[0][2])
	
#	TTF = rslt[0][0]
#	print("results:",rslt)
#	idle = results[:,1]
	temp = [rslt[0][2]]
	
	df = pd.DataFrame(data=TTF)
	df.to_csv("../results/dvfs/{}/TTF{}.csv".format(shed_policy,j))
	
#	print("rslt:",results,"\n Total time:",tok-tik)
#	print("Temp:",temp)
	tot_temp = []
	max_temp=[]
	sd_temp=[]
	allf_tot_temp = 0

	for x in temp:
		for k,fail in enumerate(x):
			corestemp = []
			maxtemp = []
			sdtemp=[]
			samp= []
			for core in fail:
#				print("cs",len(core))
				corestemp.append(np.average(core))
				maxtemp.append(np.max(core))
				sdtemp.append(np.std(core))
				samp.append(np.array(core,dtype=float))
		
#			print("samp",np.array(samp).shape)
			df = pd.DataFrame(data=samp)
			df.to_csv("../results/dvfs/fail{}.csv".format(k))
#			sys.exit()

			tot_temp.append(corestemp)
			max_temp.append(maxtemp)
			sd_temp.append(sdtemp)
			all_the_temp.append(samp)
#	print("ttttttt:",tot_temp)
#		for i in range(6):
#			tot_temp[i] += t[i]
#		allf_tot_temp += np.average(t)
#		allf_tot_temp +=t[0]
	
#	ave_temp = tot_temp/len(temp)
#	allf_ave_temp = allf_tot_temp/len(temp)
#	print("Ave Temp:",ave_temp)
#	sys.exit()
	temp_all.append(tot_temp)
#	allf_temp_all.append(allf_ave_temp)
	

	

	df = pd.DataFrame(data=tot_temp)
	df.to_csv("../results/dvfs/{}/avetemp{}.csv".format(shed_policy,j))
	
	df = pd.DataFrame(data=max_temp)
	df.to_csv("../results/dvfs/{}/maxtemp{}.csv".format(shed_policy,j))
	
	df = pd.DataFrame(data=sd_temp)
	df.to_csv("../results/dvfs/{}/sdtemp{}.csv".format(shed_policy,j))

#	df = pd.DataFrame(data=TTF)
#	df.to_csv("../results/dvfs/ttf{}.csv".format(j))
#	
#	df = pd.DataFrame(data=firstfail_time)
#	df.to_csv("../results/dvfs/firstfail{}.csv".format(j))
#	
#	df = pd.DataFrame(data=idle)
#	df.to_csv("../results/dvfs/idle{}.csv".format(j))
#	
#	df = pd.DataFrame(data=temp_all)
#	df.to_csv("../results/dvfs{}.csv".format(j))
#	
	ET_all["INT{}".format(j)]=et
	TTF_all["TTF{}".format(j)]=TTF
#	FFT_all["FFT{}".format(j)]=firstfail_time
	
#	plt.plot(firstfail,TFF,'x')
#	plt.show()

#	unique, counts = np.unique(firstfail, return_counts=True)
#	print("FF: ",dict(zip(unique, counts)))
	


#	plt.hist(TTF, density=True, bins=10)
#	plt.show()
	
#	MTTF.append(np.average(TTF))
#	ET.append(t_stop-t_start)
#	print("TTF:",TTF,"\nMTTF:",np.average(TTF),"  Mean Idle Time:",np.average(idle),"\nSD",np.std(TTF), "\nMean Execution time:",t_stop-t_start, "  Total Execution Time:",tok-tik)
	print("TTF:",TTF,"\nMTTF:",np.average(TTF),"  Mean Idle Time:",np.average(idle),"\nSD",np.std(TTF))
	j+=1

df = pd.DataFrame(data=et)
df.to_csv("../results/dvfs/{}/et.csv".format(shed_policy))
#print("MTTF:::",MTTF)




#df = pd.DataFrame(data=allf_temp_all)
#df.to_csv("../results/failtemp/allftemp.csv")


##ttfdata = {'ttf0':TTF_all[0],'fft0:':FFT_all[0],'ttf1':TTF_all[1],'fft1:':FFT_all[1],'ttf2':TTF_all[2],'fft2:':FFT_all[2]}
#df = pd.DataFrame(data=TTF_all)
#df.to_csv("../results/dvfs/ttf.csv")

#df = pd.DataFrame(data=FFT_all)
#df.to_csv("../results/dvfs/fft.csv")



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



