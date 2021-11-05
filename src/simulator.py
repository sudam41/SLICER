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
import matplotlib.pyplot as plt

import sys
import os
import copy
import subprocess

class Simulator():

	def __init__(self, app, cluster,scheduler_type,model=electro_migration):
		"""Creates a simulator to calculate the TTF, temperatures and comp_need output given a designpoint.
		"""
		self._timesteps = 0
		self._app = app
		self._cluster = cluster
		self.scheduler_type = scheduler_type
		self.model = model


	def schedule(self, scheduler_type):
		print("AT",self._app.alltasks)
		S = Scheduler(self._app, self._cluster)
		
		if scheduler_type == "MET":
			schedulable = S.MET()
		elif scheduler_type == "ETF":
			schedulable = S.ETF()
		
		return schedulable
		



		
	def simulate_thermal(self, time_intervals, num_comp, alive_components, initial_temp,thermalModel,tick,num_itter):
		"""simulate a single itteration of the thermal and aging behavior

		:return: float - wear of a single itteration
		"""
		temp_itter = []
		start_temp = np.copy(initial_temp)
#		print("starttemp:",start_temp.shape)
		prev_temp = np.copy(initial_temp)
#		print("ti:",time_intervals)
		prev_time = time_intervals[0]
		prev_power = np.zeros((num_comp,1),dtype=float)
		
		
#		time= time_intervals[0]
		power_over_time=[]
		for t in time_intervals[1:]:
		
			power = np.zeros((num_comp,1),dtype=float)
#			time = t - prev_time
			for comp in self._cluster._clus:
				if(alive_components[comp.ID] == True):
					for task in comp.assigned_tasks:
#						print("@#start:",task.start," prev+tick:",prev_time+tick, " end:", task.end, " t:",t)
						if task.start <= prev_time and task.end>= t:
#							print("YESS")
							power[comp.ID] = self._app.power[task.ID][comp.com_type]
			
			power_over_time.append(power)
			prev_time =copy.copy(t) 
			
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
		
#		print("powerover:",power_over_time)
		
		#Save power information on powertrace file
		n=num_itter
		time_all = []
		power_all = []
		end = 0
		time_all.append(time_intervals[0])
		for i in range(n):
			for t in time_intervals[1:]: 
				time_all.append(t + end )
			end = time_all[-1]
			
			for p in power_over_time:
				power_all.append(p)
				
#		print("t:",time_all,"p:",power_all)
		
		write = WriteToFile()
		write.powertrace("../MatEx/multicore2.ptrace",power_all,time_all)
		
		#Call MatEx
		subprocess.run(["../MatEx/MatEx", "-c" ,"../MatEx/matex.config", "-f" ,"../MatEx/multicore.flp", "-p", "../MatEx/multicore2.ptrace", "-transient_file_block", "../MatEx/allTemp.data"])
#		os.system("../MatEx/MatEx -c ../MatEx/matex.config -f ../MatEx/multicore.flp -p ../MatEx/multicore2.ptrace -transient_file_block ../MatEx/allTemp.data")
#		sys.exit()
		#Import temperature data from matex
		temp_matex = import_matex_data((1,2)) #TODO:change argument to the number of components
		
		temp_all = temp_matex
		
		return time_all, power_all, temp_all
		
		
		

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
		tot_num_comp = copy.copy(num_comp)
		alive_comp =  np.ones(num_comp,dtype=bool)
		initial_temp = np.zeros((num_comp,1),dtype=float)
		ageing_simulator = Ageing()
		
		current_rel = np.ones(num_comp)
		tick=0.0001
#		thermal_model = Thermal(num_comp,tick)
		thermal_model= False
		numb_itter = 4
		min_comp = 0
		schedulable = True
		
		plot = Plotter(num_comp)
		rel_res = []
		fail_time = 0
		while schedulable ==True and num_comp>min_comp:
			schedulable = self.schedule(self.scheduler_type)
###			
#			print("sched",schedulable)
#			plot.plot_schedule(self._cluster)
#			fig1, gnt = plt.subplots()
#			for i,comp in enumerate(self._cluster._clus):
##				if(alive_components[comp.ID] == True):
#				for task in comp.assigned_tasks:
#					print("comp:",comp.ID," task:",task.ID," start:",task.start," end:",task.end, " dep:",task.dep)
#					gnt.broken_barh([(task.start,task.end-task.start)],(i*1.5,1),facecolors ='tab:blue',)
#			gnt.set_yticks([0.5,2.0])
#			gnt.set_yticklabels(['Component 0', 'Component 1'])
#			gnt.set_xticks(np.arange(0,1,0.05))





			time_intervals = self._cluster.get_time_intervals()
			print(time_intervals)
			
	#		initial_temp = np.array([[45],[45]])
			
	#		initial_temp = np.zeros((20,1),dtype=float)
			
	#		print("inittempshape:",initial_temp.shape)
			

			time, power, temp = self.simulate_thermal(time_intervals,tot_num_comp, alive_comp, initial_temp,thermal_model,tick,numb_itter)
#			print("timeI: ",time)
			
			
			alive_comp, current_rel,fail_time = ageing_simulator.run(alive_comp,current_rel,time,temp,num_comp,fail_time)
			
			failed_comp = np.where(alive_comp==False)[0]
#			print("NC bef:",num_comp)
			for f in failed_comp:
				self._cluster.fail_component(f)
				
			self._cluster.reset_alive_components()
			num_comp = self._cluster.number_of_comps()
#			print("NC aft:",num_comp)

			print("Alive:", alive_comp, "CR:", current_rel )	

		
		
		plt.show()
		print("TTF:", ageing_simulator.totTime)
		return ageing_simulator.totTime

