import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


time_interval = 100 #ns
freq = 0

data1 = pd.read_csv('PeriodicPower.log',sep='\t')
data2 = pd.read_csv('markers.stat',sep=',')

power = data1['Core0-TP']


time = np.arange(0,power.size*100,100)

plt.plot(time,data1['Core0-TP'])
maximum = max(power)

liney = np.linspace(0,maximum,num=3)


prev_ts= 0

alltasks = []  
task_id=-1
for task in data2.iterrows():
	ts = task[1]['timestamp']
	name = task[1]['description']
	
	if prev_ts == ts:
		alltasks[-1][2] = alltasks[-1][2] + " + " + name
	else:
		alltasks.append([task_id,ts,name])
		task_id +=1
	prev_ts = ts
	
	
task_start = alltasks[1]
for next_task in alltasks[2:]:
	
	print("task -",task_start[0],"  -->  ",task_start[1]," : ",next_task[1]," time=",next_task[1]-task_start[1])
	
	task_power = power[int(task_start[1]/100):int(next_task[1]/100)]
	data = {"Core_1,1":task_power}
	df = pd.DataFrame(data = data)
	df.to_csv("task_traces/Task{}_f{}.ptrace".format(task_start[0],freq),index = False,sep='\t')	
	task_start = next_task

print(len(alltasks),len(data1))
#plt.xlabel("time(ns)")
#plt.ylabel("power(w)")
#plt.legend()
#plt.show()
