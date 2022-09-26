#!/usr/bin/env python

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import sys

#interval = 0.01
interval  =  0.0000001

def generate_power_data(timeperiod,task):

#	timeperiod = 0.1
	numb_values = timeperiod/interval

	strt = 0
	stop = strt+timeperiod
	
	print("strt:",strt," stop",stop,"  interval:",interval)
	if timeperiod <0.29:
		tim = np.arange(strt,stop-interval,interval)
	else:
		tim = np.arange(strt,stop,interval)
	print("tim:",tim)
	powr2 = np.exp(tim)
	powr1 = (np.exp(tim)/0.2) +0.4

	##print("tim",tim,"\npow",powr)
	plt.plot(tim,powr1)
	plt.plot(tim,powr2)
	plt.show()

	#for i in range(numb_values):
	
	print("t:",tim.size,"  p1:",powr1.size,"  p2:",powr2.size)

	data = {"Core_1,1":powr1,"Core_1,2":powr2}
	df = pd.DataFrame(data = data)

	df.to_csv("Task{}.ptrace".format(task),index = False,sep='\t')




###################################################






def store_pwer_data(data,task,freq):
	powr1 = data
	print("Mean:",np.mean(powr1))
#	powr2 = data
	data = {"Core_1,1":powr1}

	df = pd.DataFrame(data = data)

	df.to_csv("Task{}_f{}.ptrace".format(task,freq),index = False,sep='\t')
	

	
data1 = pd.read_csv('PeriodicPower_1.log',sep='\t')
data2 = pd.read_csv('PeriodicPower_2.log',sep='\t')
data3 = pd.read_csv('PeriodicPower_3.log',sep='\t')
data4 = pd.read_csv('PeriodicPower_4.log',sep='\t')

#print(data4['Core0-TP'])
#plt.plot(data4['Core0-TP'])
#plt.show()
#sys.exit()
for task in range(6):
	store_pwer_data(data1['Core0-TP'],task,0)
	store_pwer_data(data2['Core0-TP'],task,1)
	store_pwer_data(data3['Core0-TP'],task,2)
	store_pwer_data(data4['Core0-TP'],task,3)



#numb_tasks = 4
##tasktimes= [0.3,0.1,0.2,0.2]
#tasktimes = [0.028,0.028,0.028,0.028]
#for i in range(numb_tasks):
##	generate_power_data(tasktimes[i],i)
#	store_pwer_data(data,i)
