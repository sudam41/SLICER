import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


import os 

for subdir, dirs, files in os.walk("./"):
#	print(subdir)
#	print("--------")
	for directory in dirs:
		if directory[0:6] == "result":
#			print(dire)
			source_dir =  subdir + os.sep + directory
			benchmark = subdir[2:]
			freq = directory[25:31]
			target_dir = "../powertraces/"+benchmark+"/"+freq
#			print("filepath: ", target_dir)
			print("Benchmark: ",benchmark,"\tFrequency: ",freq)
			print("Source path: ",source_dir)

			if not os.path.exists(target_dir):

			   # Create a new directory because it does not exist
			   os.makedirs(target_dir)
			   print("New directory created: {}".format(target_dir))




			time_interval = 100 #ns
			freq = 0

			data1 = pd.read_csv(source_dir+"/PeriodicPower.log",sep='\t')
			data2 = pd.read_csv(source_dir+"/markers.stat",sep=',')

			power = data1['Core0-TP']


			time = np.arange(0,power.size*100,100)

			plt.plot(time,data1['Core0-TP'])
			maximum = max(power)

			liney = np.linspace(0,maximum,num=3)


			prev_ts= 0

			alltasks = []  
			task_id=0
			tasknames = []
			tasksizes = []
			for task in data2.iterrows():
				ts = task[1]['timestamp']
				name = task[1]['description']
				tasknames.append(name)
			#	if prev_ts == ts:
			#		alltasks[-1][2] = alltasks[-1][2] + " + " + name
			#	else:
			#		alltasks.append([task_id,ts,name])
			#		task_id +=1

				alltasks.append([task_id,ts,name])
				task_id +=1

				prev_ts = ts
				
			print(alltasks)	
			task_start = alltasks[0]
			for next_task in alltasks[1:]:
				
				print("task -",task_start[0],"  -->  ",task_start[1]," : ",next_task[1]," time=",next_task[1]-task_start[1])
				
				task_power = power[int(task_start[1]/100):int(next_task[1]/100)]
				data = {"Core_1,1":task_power}
				tasksizes.append(len(task_power))
				df = pd.DataFrame(data = data)
				df.to_csv("{}/Task{}_{}.ptrace".format(target_dir,task_start[0],task_start[2]),index = False,sep='\t')	
				task_start = next_task

			task_power = power[int(task_start[1]/100):]
			data = {"Core_1,1":task_power}
			tasksizes.append(len(task_power))
			df = pd.DataFrame(data = data)
			df.to_csv("{}/Task{}_{}.ptrace".format(target_dir,task_start[0],task_start[2]),index = False,sep='\t')	

			print(len(tasknames),len(tasksizes))
			taskdata = {"task":tasknames,"size":tasksizes}
			df = pd.DataFrame(data = taskdata)
			df.to_csv("{}/taskdata.csv".format(target_dir,task_start[0],task_start[2]),index = False,sep='\t')

			print(len(alltasks),len(data1))
			#plt.xlabel("time(ns)")
			#plt.ylabel("power(w)")
			#plt.legend()
			#plt.show()
