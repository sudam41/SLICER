#!/usr/bin/env python

""" This file contains most top-level functionality in order to evaluate a designpoint.

Functionalities of the simulator should be defined in the integrator.py file.
"""

import numpy as np
from electromigration import electro_migration
from scheduler import Scheduler
#from thermal import Thermal
from plotter import Plotter
from savepowertrace import WriteToFile
from matexdata import import_matex_data
from ageing import Ageing
from parse_power_trace import parse_power



import matplotlib.pyplot as plt
import pandas as pd
import math

import sys
import os
import copy
import subprocess
import time as TT

class Simulator():

	def __init__(self, app, cluster,scheduler_type,ageing_interval,pow_ave_interval,num_itter,mc_instance,model=electro_migration):
		"""Creates a simulator to calculate the TTF, temperatures and comp_need output given a designpoint.
		"""
		self._timesteps = 0
		self._app = app
		self._cluster = cluster
		self.scheduler_type = scheduler_type
		self.model = model
		
		self.ageing_interval = ageing_interval
		self.pow_ave_interval = pow_ave_interval
		self.num_itter = num_itter
		self.mc_instance = mc_instance


	def schedule(self, scheduler_type):
#		print("AT",self._app.alltasks)
#		print("CLUS:",len(self._cluster._clus))
#		x= input("input X: ")
		S = Scheduler(self._app, self._cluster,scheduler_type)
		
		if scheduler_type == "MET":
			schedulable = S.MET()
		elif scheduler_type == "ETF":
			schedulable = S.ETF()
		elif scheduler_type == "HEFT":
			schedulable = S.HEFT()
		elif scheduler_type == "DNDS":
			schedulable = S.DNDS()
		elif scheduler_type == "DWDS":
			schedulable = S.DWDS()
		return schedulable
		



		
	def simulate_thermal(self, time_intervals, num_comp, alive_components, initial_temp,thermalModel,tick,num_itter):
		"""simulate a single itteration of the thermal behavior

		:return: float - wear of a single itteration
		"""
		temp_itter = []
		start_temp = np.copy(initial_temp)
#		print("starttemp:",start_temp.shape)
		prev_temp = np.copy(initial_temp)
#		print("ti:",time_intervals)
		prev_time = time_intervals[0]
		prev_power = np.zeros((num_comp,1),dtype=float)
		
		num_alive = 0
		for c in alive_components:
			if c==True:
				num_alive+=1
		
		
		tic = TT.perf_counter()  ##Timing
		
		ptrace = True
		# interval = 0.001
		# interval = 0.0000001
		interval = 0.0000001 #=100ns
		
		tasks_over_time=[]
#		time= time_intervals[0]
		power_over_time=[]
		for t in time_intervals[1:]:
			
			assigned_tasks = np.empty(num_comp)
			assigned_tasks[:] = np.NaN
			power = np.zeros((num_comp,1),dtype=float)
#			time = t - prev_time
			for comp in self._cluster._clus:
				if(alive_components[comp.ID] == True):
					for task in comp.assigned_tasks:
#						print("@#start:",task.start," prev+tick:",prev_time+tick, " end:", task.end, " t:",t)
						if task.start <= prev_time and task.end>= t:
#							print("YESS")

							if ptrace == False:
								power[comp.ID] = self._app.power[task.ID][comp.com_type]
							else:
								assigned_tasks[comp.ID] = task.ID
#								print("Tid",task.ID)
								
			tasks_over_time.append(assigned_tasks)
			# power_over_time.append(power)
			prev_time =copy.copy(t) 
			

		self._cluster._clus[0].order_assigned_tasks()
#		print("cluster:",self._cluster._clus)
		power_all_p = []
		
		idle_time = np.zeros(num_comp)
		for i in range (len(alive_components)):
			power_all_p.append(np.zeros(1))
			
#		print("ac:",alive_components)
		for c in range (len(alive_components)):
#		for comp in self._cluster._clus:
#			print("Comp:",c)
			if(alive_components[c] == True):
				comp = self._cluster.find_alive_component(c)
				pow_data = np.empty(int(round(self._app.deadline/interval)))
#				print("ip",self._cluster.idle_power)
				pow_data.fill(self._cluster.idle_power[comp.curr_freq])
				comp.order_assigned_tasks()
				idle_time[c] = comp.idletime(self._app.deadline)
				for task in comp.assigned_tasks:
					# print("task start:",task.start," task end:",task.end/interval)
					start = int(round(task.start/interval))
					end = int(round(task.end/interval))
#					print("task:",task.ID,"  start:",start,"  stop:",end)
					# pow_data[start:end] = parse_power(task.ID,comp.com_type,comp.curr_freq)
					# print("pow:",self._app.power[comp.com_type][comp.curr_freq][task.ID])
					pow_data[start:end] = self._app.power[comp.com_type][comp.curr_freq][task.ID]
					# sys.exit()
					
			else:
				pow_data = np.zeros(int(round(self._app.deadline/interval)))
			
			# print("powdata:",len(pow_data)," comp:",c)
			pow_data_list = []
			for j in range(num_itter):
				pow_data_list.append(pow_data)
			power_all_p[c]= np.concatenate(tuple(pow_data_list)) 
			
#			print("new_powdata:",len(power_all_p[c])," comp:",c)
		# time_all_p = np.arange(0,self._app.deadline*num_itter,interval)
		time_all_p = np.linspace(0,self._app.deadline*num_itter,len(power_all_p[0]))


		# print("TIME:",len(time_all_p))
#		sys.exit()


		#Averaging each num_sample values
		average = False
		if average:

#			for i in range(len(power_all_p)):
#				power_all_p[i] = np.delete(power_all_p[i],0)
			
			num_sample = self.pow_ave_interval
			
			power_size = power_all_p[0][1:].size
#			print("PS",power_size,"TS",time_all_p.size)
			power_all_ave=[]
			
			time_all_ave = time_all_p[::num_sample]
			for com in range(num_comp):
				if power_size%num_sample !=0:
					pow_com = np.insert(power_all_p[com][1:],-1,np.zeros(num_sample-(power_size%num_sample)))
					
				else:
					pow_com = power_all_p[com][1:]
					
#				print("nfgfh:",num_sample-(power_size%num_sample),"  Powcom",pow_com.size)
				
				power_all_ave.append( np.mean(pow_com.reshape(-1,num_sample),1))
#				power_all_ave.append( np.mean(power_all_p[com][0:(math.floor(power_size/num_sample)*num_sample)].reshape(-1,num_sample),1))
				power_all_ave[com] = np.insert(power_all_ave[com],0,0)
#			
			time_all_ave = np.insert(time_all_ave,0,-1)



		elif ptrace==True:	
			time_all_ave = time_all_p
			power_all_ave = power_all_p
#			time_all_ave = np.insert(time_all_ave,0,-1)
#			print("TIM SIZE:",time_all_ave.size,"  AVE SIZE:",power_all_ave[1].size)
		else:
			time_all_ave = time_all
			power_all_ave = power_all
		

		
		time_all_ave = np.insert(time_all_ave,0,-1)
		for i in range(len(power_all_ave)):
			power_all_ave[i] = np.insert(power_all_ave[i],0,np.average(power_all_ave[i]))

			if len(time_all_ave) != len(power_all_ave[i]):
				print( len(time_all_ave), len(power_all_ave[i]))
				print("ERROR: values not equal!")
				sys.exit()

		# print(power_all_ave[0])
		# sys.exit()
		# print("here!")
		write = WriteToFile()
		if ptrace == False:
#			print("here")
			write.powertrace("../MatEx/multicore2.ptrace",power_all,time_all)
#			print("Call Matex")
			subprocess.run(["../MatEx/MatEx", "-c" ,"../MatEx/matex.config", "-f" ,"../MatEx/multicore.flp", "-p", "../MatEx/multicore2.ptrace", "-transient_file_block", "../MatEx/allTemp.data"])
#			print("Matex completed")
		else:
#			print("write power")
#			tic = TT.perf_counter()  ##Timing
			write.powertrace_all("../MatEx/powertraces/instance_{}.ptrace".format(self.mc_instance),power_all_ave,time_all_ave,self._cluster.names,0.4)
#			print("Call Matex")
			toc = TT.perf_counter()  ##Timing
#			print("Time to write power:",toc-tic)
			# print("powertraces written!!")
			# sys.exit()
			
			print("Matex started")
			subprocess.run(["../MatEx/MatEx", "-c" ,"../MatEx/matex.config", "-f" ,"../MatEx/floorplans/nehalem.flp", "-p", "../MatEx/powertraces/instance_{}.ptrace".format(self.mc_instance), "-transient_file_block", "../MatEx/results/allTemp_{}.data".format(self.mc_instance)])
			tic = TT.perf_counter()  ##Timing
#			sys.exit()
			print("Matex completed")
			# sys.exit()
			os.remove("../MatEx/powertraces/instance_{}.ptrace".format(self.mc_instance))
			
			toc = TT.perf_counter()  ##Timing

		temp_matex = import_matex_data(self._cluster.names,self.mc_instance) #TODO:change argument to the number of components
		
		temp_all = temp_matex
		# print("temp_all:",len(temp_all))
		# sys.exit()
		return time_all_ave, power_all_ave, temp_all, np.sum(idle_time)/num_alive, 
		
		
		


	def run(self):
		""" Run the simulation 
		"""
		num_comp = self._cluster.number_of_comps()
#		print("@no of comps:",num_comp)
		tot_num_comp = copy.copy(num_comp)
		alive_comp =  self._cluster.enabled_comp#np.ones(num_comp,dtype=bool)#enabed comp here
#		print("ac:",alive_comp)
		initial_temp = np.zeros((num_comp,1),dtype=float)
		data = {}
		ageing_simulator = Ageing(data,self.ageing_interval)
		
		current_rel = np.ones(len(alive_comp))
		tick=0.0001
#		thermal_model = Thermal(num_comp,tick)
		thermal_model= False
		numb_itter = self.num_itter
		min_comp = 1
		schedulable = True
		
		tot_idle_time=0
		tot_temp=[]
		
#		plot = Plotter(num_comp)
		firstrun = True
		fail_time = 0
		failcount=0
		firstfail_time=0
		firstfail = 0
		
		no_tasks = []

		failed_order = []
		failed_times = []
		
		execution_time = []
		
		tot_sys_power = []
		while schedulable ==True and num_comp>min_comp:
		
			
			tic_sch = TT.perf_counter()  ##Timing
			schedulable = self.schedule(self.scheduler_type)
			toc_sch = TT.perf_counter()  ##Timing
			if schedulable ==False:
				print("%%%%%%NOT Schedulable!!%%%%%")
				break
#			print("schedule time:",toc_sch-tic_sch)
##		
#			print("sched",schedulable)
#			plot.plot_schedule(self._cluster)
#			fig1, gnt = plt.subplots()
#			for i,comp in enumerate(self._cluster._clus):
#				if(alive_comp[comp.ID] == True):
#					for task in comp.assigned_tasks:
#						print("comp:",comp.ID," task:",task.ID," start:",task.start," end:",task.end, " dep:",task.dep)
#						gnt.broken_barh([(task.start,task.end-task.start)],(i*1.5,1),facecolors ='tab:blue',)
#			gnt.set_yticks([0.5,2.0])
#			gnt.set_yticklabels(['Component 0', 'Component 1'])
#			gnt.set_xticks(np.arange(0,1,0.05))

			shed = []
			tasks_per_comp = []
			for i,comp in enumerate(self._cluster._clus):
				tasks_per_comp.append(len(comp.assigned_tasks))
				for task in comp.assigned_tasks:
					shed.append([task.ID,comp.ID,comp.curr_freq,task.start,task.end])		
			
			
			no_tasks.append(tasks_per_comp)
#			df = pd.DataFrame(data=shed)
#			df.to_csv("../results/dvfs/shedule_heft_2core{}.csv".format(failcount))
			failcount+=1
			# print("schedule:"," (task.ID, comp.ID, comp.curr_freq, task.start, task.end)\n",np.array(shed))
#			sys.exit()

#			tic = TT.perf_counter()  ##Timing
			time_intervals = self._cluster.get_time_intervals()
			
			execution_time.append(time_intervals[-1])
#			toc = TT.perf_counter()  ##Timing
#			print("TI time:",toc-tic)
#			print(time_intervals)
			
	#		initial_temp = np.array([[45],[45]])
			
	#		initial_temp = np.zeros((20,1),dtype=float)
			
	#		print("inittempshape:",initial_temp.shape)
			
#			tic = TT.perf_counter()  ##Timing
			# print("before simulate thermal")
			time, power, temp, idle = self.simulate_thermal(time_intervals,tot_num_comp, alive_comp, initial_temp,thermal_model,tick,numb_itter)
#			toc = TT.perf_counter()  ##Timing
#			print("Thermal time:",toc-tic)
#			print("temp for failure:",len(temp[1:]))
#			print("temp len:",self._cluster.number_of_comps())
#			tot_temp.append((np.sum(temp[1:]))/self._cluster.number_of_comps())
			
			sys_power = np.sum(power,axis=0)
			tot_sys_power.append(sys_power)
#			print("power:",len(power)," sys power:",len(sys_power))
			
#			df = pd.DataFrame(data=temp)
#			df.to_csv("../results/dvfs/temp_heft_2core{}.csv".format(failcount))
##			sys.exit()
			
			
			tot_temp.append(temp[0:])
			# print
#			print("timeI: ",time)
#			fig, ax = plt.subplots(2,1)
#			
#			ax[0].plot(temp[0][0:],temp[1][0:])
#			ax[0].set_title("core 0")
#			ax[1].plot(temp[0][0:],temp[2][0:])
#			ax[1].set_title("core 1")
			
			tic = TT.perf_counter()  ##Timing
			alive_comp, current_rel,fail_time,comp_failed = ageing_simulator.run(alive_comp,current_rel,time_intervals,temp,num_comp,fail_time)
			toc = TT.perf_counter()  ##Timing
#			print("Ageing time:",toc-tic)

			failed_order.append(comp_failed)
			failed_times.append(fail_time)

			ittr_time= time_intervals[-1]
			no_itter_to_fail = fail_time*60*60/ittr_time
			idle_time = (idle*no_itter_to_fail)/3600
			tot_idle_time+=idle_time
#			print("tot_idle:",idle_time, "  fail_time:",fail_time)
			
			failed_comps = np.where(alive_comp==False)[0]
			
			
			for f in failed_comps:
				self._cluster.fail_component(f)
				
			self._cluster.reset_alive_components()
			num_comp = self._cluster.number_of_comps()
#			print("NC aft:",num_comp)

#			print("Alive:", alive_comp, "CR:", current_rel )	

			if firstrun ==True:
				firstfail = failed_comps[0]
				firstfail_time = copy.copy(ageing_simulator.totTime)
				firstrun=False
#			print("F:",firstfail)
		

#		MultiAve = (aveA*n1 + aveB*n2 + aveC*n3)/(n1+n2+n3)
		noHyperPeriods = np.floor(np.array(failed_times)/self._app.deadline)
		AvePower = np.sum(np.multiply([np.average(tot_sys_power,axis=1)],noHyperPeriods))/np.sum(noHyperPeriods)

#		MultiVAR = (np.sum(np.square(A-MultiAve))*n1 + np.sum(np.square(B-MultiAve))*n2 + np.sum(np.square(C-MultiAve))*n3)/((n1+n2+n3)*8)
		VarPower = np.sum(np.multiply(np.sum(np.square(tot_sys_power - AvePower),axis=1),noHyperPeriods))/(np.sum(noHyperPeriods)*len(tot_sys_power[0]))
#		print("execution times",execution_time)
		AvePowHype = np.average(tot_sys_power,axis=1)
		VarPowHype = np.var(tot_sys_power,axis=1)
#		print("AvePow",AvePowHype," VarPow",VarPowHype)
#		sys.exit()
#		##Store alpha values for plotting
#		print("DATA:",data)
#		df = pd.DataFrame(data=data)
#		df.to_csv("data.csv")
#		print("Temptemp[1:]:", len(tot_temp[0]))
#		sys.exit()
#		print("FO:",failed_order)
		
#		return firstfail_time,firstfail, ageing_simulator.totTime, tot_idle_time, tot_temp
		return ageing_simulator.totTime, tot_idle_time, tot_temp, [AvePower,VarPower], failed_order,failed_times,execution_time,[AvePowHype,VarPowHype],no_tasks

