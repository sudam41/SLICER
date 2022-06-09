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
		interval = 0.001
#		interval = 0.0000001
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
			power_over_time.append(power)
			prev_time =copy.copy(t) 
			
#		toc = TT.perf_counter()  ##Timing
#		print("Time to assign tasks:",toc-tic)
#		print("clus:",self._cluster._clus)
#		print("\ntot:",tasks_over_time)
		
##		idle_time = np.zeros(num_comp)
##		for i,t in time_intervals[1:]:
##			for c,tsk in enumerate(tasks_over_time[i]):

#			Plot = Plotter(num_comp)
#			Plot.plot_power(time_intervals,power_over_time)
			##############
###			print("power:",power,np.zeros((18,1)))
##			power_all = np.concatenate((power,np.zeros((18,1))),axis=0)


##			
##			temp_itter = temp_itter + thermalModel.step_all(start_temp,power_all,prev_time,t,tick)
##				
##			start_temp = temp_itter[-1][1]
##			prev_time = temp_itter[-1][0]
#			#############
#			
##			print("P:",power,"\nPP:",prev_power)
#			withpower = thermalModel.step_with_power_change(prev_time, tick, power,prev_power,start_temp,prev_temp)
#			print("size",len(withpower))
#			temp_itter = temp_itter + withpower
#			

#			prev_time = temp_itter[-1][0]
#			prev_temp = np.copy(start_temp)
#			start_temp = temp_itter[-1][1]
##			print("After prev:",prev_temp,"\nstart:",start_temp)
#			
#			withoutpower = thermalModel.step_without_power_change(prev_time,t,tick,start_temp,prev_temp)
#			print("size",len(withoutpower))
#			temp_itter = temp_itter + withoutpower
##			print("without power:",temp_itter[-1])

#			
#			prev_power = np.copy(power)
#			prev_time = temp_itter[-1][0]
#			prev_temp = np.copy(start_temp)
#			start_temp = temp_itter[-1][1]
##			print("temp_ittr:",len(temp_itter))
##			print("prevtemp_simu:",prev_temp)
#			
##			samples[alive_components] = self.model(temp[alive_components]) * np.random.weibull(5.0,np.sum(alive_components))
##			wear[alive_components] += np.divide(1, np.floor(samples), out=np.zeros_like(samples), where=samples != 0)
		
		
#		tic = TT.perf_counter()  ##Timing
		
		
#		print("powerover:",power_over_time)
#		print("TOT:",tasks_over_time)
############
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
					start = int(round(task.start/interval))
					end = int(round(task.end/interval))
#					print("task:",task.ID,"  start:",start,"  stop:",end)
					pow_data[start:end] = parse_power(task.ID,comp.com_type,comp.curr_freq)
					
					
			else:
				pow_data = np.zeros(int(round(self._app.deadline/interval)))
			
#			print("powdata:",len(pow_data)," comp:",c)
			pow_data_list = []
			for j in range(num_itter):
				pow_data_list.append(pow_data)
			power_all_p[c]= np.concatenate(tuple(pow_data_list)) 
			
#			print("new_powdata:",len(power_all_p[c])," comp:",c)
		time_all_p = np.arange(0,self._app.deadline*num_itter,interval)
#		print("TIME:",len(time_all_p))
#		sys.exit()





#############
#		#Save power information on powertrace file
#		n=num_itter
#		time_all = []
#		power_all = []
#		
##		time_all_p = np.zeros(1)
#		
#		power_all_p = []

#		for i in range (len(alive_components)):
#			power_all_p.append(np.zeros(1))
#		
#		
#		end = 0
#		time_all.append(time_intervals[0])
#		for i in range(n):
#			idle_time = np.zeros(num_comp)
#			if ptrace == False:
#				for t in time_intervals[1:]: 
##					time_all.append(t + end )
#					time_all.append(t + self._app.deadline )
#				end = time_all[-1]
#				
#				for p in power_over_time:
#					power_all.append(p)
#			else:
#				prev_task = ["x","x","x","x","x","x","x","x","x","x","x","x","x","x","x","x"] #TODO***********
##				time_all_p = np.concatenate((time_all_p,np.arange(end,time_intervals[-1]+end,interval)))
#				for j,t in enumerate(time_intervals[1:]):
##					tim = np.arange(time_intervals[j]+end,t+end,interval)
#					
##					print("timallp:",time_all_p,"  tim:",tim)
##					timtried toe_all_p=np.concatenate((time_all_p,tim),axis=0)
#					
#					comps = tasks_over_time[j]
#					print("tasks_over_time:",tasks_over_time[-1])
##					for c,tsk in enumerate(comps):
#					for c in range(len(alive_components)):
##						print("comp:",c)
#						if alive_components[c]:
#							
#							tsk = comps[c]
##							print("task:",tsk,"   prev:",prev_task[c])
#							if prev_task[c]!=tsk:
#								if tsk==tsk:
#									pow_data = parse_power(int(tsk),c)#TODO: also pass in the dvfs level
#								else:
##									print("AC:",alive_components)	
#									pow_data = np.empty(int(round((t-time_intervals[j])/interval)))
#									pow_data.fill(self._cluster.idle_power)
##									print("idle pow:",pow_data)
#									idle_time[c]+=t-time_intervals[j]
#								if time_intervals[-1]==t:
#									pow_data_idle = np.empty(int(round((self._app.deadline-t)/interval)))
#									pow_data_idle.fill(self._cluster.idle_power)
#									pow_data = np.concatenate((pow_data,pow_data_idle))
#							else:
#								if time_intervals[-1]==t:
#									pow_data = np.empty(int(round((self._app.deadline-t)/interval)))
#									pow_data.fill(self._cluster.idle_power)
##									pow_data = np.concatenate((pow_data,pow_data_idle))
##								continue
#							
#							
#						else:
#							if time_intervals[-1]==t:
#								pow_data = np.zeros(int(round((self._app.deadline-time_intervals[j])/interval)))
#							else:
#								pow_data = np.zeros(int(round((t-time_intervals[j])/interval))) 
#							
#							
##							print("dead pow:",pow_data)
#							
#						print("pow size:",len(pow_data))	

#						power_all_p[c]=np.concatenate((power_all_p[c],pow_data))
#							
#					prev_task = copy.deepcopy(comps)		
##				end = time_all_p[-1]
##				end += time_intervals[-1]
#				end+=self._app.deadline			
##			print("Idle Time:",np.sum(idle_time)/num_alive,"  Total time:", time_intervals[-1])	
##		print("end:",end)	
##		print("PA:",power_all_p)
##		sys.exit()
##		time_all_p = np.arange(time_intervals[0],end,interval)
#		time_all_p = np.linspace(time_intervals[0],end,int(round((end-time_intervals[0])/interval)))
##		print
##				for comps in tasks_over_time:
##					for t,c in enumerate(comps):
##						print("tasks:",t,"  comp:",c)
##						if t==t:
##							p = parse_power(t,c)
##							power_all_p[i]=np.concatenate((power_all_p[i],p))
##						else:
#		
#		
##		toc = TT.perf_counter()  ##Timing
##		print("Time to parse power:",toc-tic)					
#				
##		print("t:",time_all,"\np0:",power_all,"\np1:",power_all_p[1].size)
#		
###plot w ptrace
###		time_all_p = np.delete(time_all_p,0)
##		plt.plot(time_all_p,power_all_p[0][1:],color='red')
##		plt.plot(time_all_p,power_all_p[1][1:],color='blue')
##		plt.xlabel('Time')
##		plt.ylabel('Power')
##		plt.show()
#		

####plot w/o ptrace
##		ttt= np.array([0])
##		ppp1 = np.array([0])
##		ppp2 = np.array([0])
##		pw1 = np.zeros(len(time_all))
##		pw2 = np.zeros(len(time_all))
##		for i,t in time_all[1:]:
##			tim = np.linspace(time_all[i],t,10)
##			pww1 = np.ones(10)*power_all[i][0][0]
##			pww2 = np.ones(10)*power_all[i][1][0]
##			
##			ttt=np.concatenate(ttt,tim)
##			ppp1 =np.concatenate(ppp1,pww1)
##			ppp2 =np.concatenate(ppp2,pww2)
##			
##		plt.plot(ttt,ppp1)
##		plt.show()	


##		for i,p in enumerate(power_all):
##			pw1[i] = p[0][0]
##			pw2[i] = p[1][0]
##			
##		
##		print("pw:",pw1)
##		
##		plt.plot(time_all,pw1,color='red')
##		plt.plot(time_all,pw2,color='blue')
##		plt.xlabel('Time')
##		plt.ylabel('Power')
##		plt.show()

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

##			if power_size%num_sample !=0:
##				time_all_ave = np.insert(time_all_ave,-1,time_all_ave[-1]+interval)
#			time_all_ave[0]=-1
#			
#			print("TIM SIZE:",time_all_ave.size,"  AVE SIZE:",power_all_ave[2].size)
#			print("Diff:", np.sum(power_all_ave[2]-power_all_p[2][1:]))

		elif ptrace==True:	
			time_all_ave = time_all_p
			power_all_ave = power_all_p
#			time_all_ave = np.insert(time_all_ave,0,-1)
#			print("TIM SIZE:",time_all_ave.size,"  AVE SIZE:",power_all_ave[1].size)
		else:
			time_all_ave = time_all
			power_all_ave = power_all
		
#		print("t.begin:",time_all[0],"  t.end:",time_all[-1])
#		print("TIM SIZE:",time_all_ave.size,"  AVE SIZE:",power_all_ave[1].size)
#		sys.exit()

		

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
			write.powertrace_all("../MatEx/powertraces/instance_{}.ptrace".format(self.mc_instance),power_all_ave,time_all_ave,self._cluster.names)
#			print("Call Matex")
			toc = TT.perf_counter()  ##Timing
#			print("Time to write power:",toc-tic)
			
			
			print("Matex started")
			subprocess.run(["../MatEx/MatEx", "-c" ,"../MatEx/matex.config", "-f" ,"../MatEx/floorplans/multicore_3x3.flp", "-p", "../MatEx/powertraces/instance_{}.ptrace".format(self.mc_instance), "-transient_file_block", "../MatEx/results/allTemp_{}.data".format(self.mc_instance)])
			tic = TT.perf_counter()  ##Timing
#			sys.exit()
			print("Matex completed")
			os.remove("../MatEx/powertraces/instance_{}.ptrace".format(self.mc_instance))
			
			toc = TT.perf_counter()  ##Timing
#			print("Time to remove file:",toc-tic)
#			print("File removed!")
			
			
			
			
#		ip = input()
#		sys.exit()
		#Call MatEx
		
#		os.system("../MatEx/MatEx -c ../MatEx/matex.config -f ../MatEx/multicore.flp -p ../MatEx/multicore2.ptrace -transient_file_block ../MatEx/allTemp.data")
#		sys.exit()
		#Import temperature data from matex
#		sys.exit()
		temp_matex = import_matex_data(self._cluster.names,self.mc_instance) #TODO:change argument to the number of components
		
		temp_all = temp_matex
#		print("temp_all:",len(temp_all))
		return time_all_ave, power_all_ave, temp_all, np.sum(idle_time)/num_alive 
		
		
		

##		temp_comp =[]
##		for t in temp_itter:
##			temp_comp.append((t[0],t[1][:num_comp]))
#			
##		print("temp_comp",temp_comp)
##		sys.exit()
#		Plot = Plotter(len(self._cluster._clus))
#		Plot.plot_schedule(self._cluster)
		
#		Plot.plot_power(time_intervals,power_over_time)
#		Plot.plot_temp(temp_comp)
#		
#		return wear
	       	 
#	def simulate_ageing(self,alive_comp,current_rel,time_intervals,temp,num_comp):
#		ageing_simulator = Ageing()
#		return ageing_simulator.run(alive_comp,current_rel,time_intervals,temp,num_comp)
	       

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
			for i,comp in enumerate(self._cluster._clus):
				for task in comp.assigned_tasks:
					shed.append([task.ID,comp.ID,comp.curr_freq,task.start,task.end])		
			
			df = pd.DataFrame(data=shed)
			df.to_csv("../results/dvfs/shedule_heft_2core{}.csv".format(failcount))
			failcount+=1
			print("schedule:",np.array(shed))
#			sys.exit()

#			tic = TT.perf_counter()  ##Timing
			time_intervals = self._cluster.get_time_intervals()
#			toc = TT.perf_counter()  ##Timing
#			print("TI time:",toc-tic)
#			print(time_intervals)
			
	#		initial_temp = np.array([[45],[45]])
			
	#		initial_temp = np.zeros((20,1),dtype=float)
			
	#		print("inittempshape:",initial_temp.shape)
			
#			tic = TT.perf_counter()  ##Timing
			time, power, temp, idle = self.simulate_thermal(time_intervals,tot_num_comp, alive_comp, initial_temp,thermal_model,tick,numb_itter)
#			toc = TT.perf_counter()  ##Timing
#			print("Thermal time:",toc-tic)
#			print("temp for failure:",len(temp[1:]))
#			print("temp len:",self._cluster.number_of_comps())
#			tot_temp.append((np.sum(temp[1:]))/self._cluster.number_of_comps())
			
			df = pd.DataFrame(data=temp)
			df.to_csv("../results/dvfs/temp_heft_2core{}.csv".format(failcount))
#			sys.exit()
			
			
			tot_temp.append(temp[0:])
			
#			print("timeI: ",time)
#			fig, ax = plt.subplots(2,1)
#			
#			ax[0].plot(temp[0][0:],temp[1][0:])
#			ax[0].set_title("core 0")
#			ax[1].plot(temp[0][0:],temp[2][0:])
#			ax[1].set_title("core 1")
			
			tic = TT.perf_counter()  ##Timing
			alive_comp, current_rel,fail_time = ageing_simulator.run(alive_comp,current_rel,time_intervals,temp,num_comp,fail_time)
			toc = TT.perf_counter()  ##Timing
#			print("Ageing time:",toc-tic)
			
			ittr_time= time_intervals[-1]
			no_itter_to_fail = fail_time*60*60/ittr_time
			idle_time = (idle*no_itter_to_fail)/3600
			tot_idle_time+=idle_time
#			print("tot_idle:",idle_time, "  fail_time:",fail_time)
			
			failed_comp = np.where(alive_comp==False)[0]
#			print("NC bef:",num_comp)
			for f in failed_comp:
				self._cluster.fail_component(f)
				
			self._cluster.reset_alive_components()
			num_comp = self._cluster.number_of_comps()
#			print("NC aft:",num_comp)

#			print("Alive:", alive_comp, "CR:", current_rel )	

			if firstrun ==True:
				firstfail = failed_comp[0]
				firstfail_time = copy.copy(ageing_simulator.totTime)
				firstrun=False
#			print("F:",firstfail)
		
#		##Store alpha values for plotting
#		print("DATA:",data)
#		df = pd.DataFrame(data=data)
#		df.to_csv("data.csv")
#		print("Temptemp[1:]:", len(tot_temp[0]))
#		sys.exit()
		
		return firstfail_time,firstfail, ageing_simulator.totTime, tot_idle_time, tot_temp

