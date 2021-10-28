#!/usr/bin/env python

""" This file contains most top-level functionality in order to evaluate a designpoint.

Functionalities of the simulator should be defined in the integrator.py file.
"""

import numpy as np
from electromigration import electro_migration
from scheduler import Scheduler
from thermal import Thermal
from plotter import Plotter

import sys

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

		S = Scheduler(self._app, self._cluster)
		
		if scheduler_type == "MET":
			schedulable = S.MET()
		elif scheduler_type == "ETF":
			schedulable = S.ETF()
		
		return schedulable
		



		
	def simulate_itteration(self, time_intervals, num_comp, alive_components, initial_temp,thermalModel,tick):
		"""simulate a single itteration of the thermal and aging behavior

		:return: float - wear of a single itteration
		"""
		temp_itter = []
		start_temp = np.copy(initial_temp)
#		print("starttemp:",start_temp.shape)
		prev_temp = np.copy(initial_temp)
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
#						print("start:",task.start," prev+tick:",prev_time+tick, " end:", task.end, " t:",t)
						if task.start <= prev_time+tick and task.end>= t:
							power[comp.ID] = self._app.power[task.ID][comp.com_type]
			
			power_over_time.append(power)
			
#			print("power:",power,np.zeros((18,1)))
			power_all = np.concatenate((power,np.zeros((18,1))),axis=0)


			
			temp_itter = temp_itter + thermalModel.step_all(start_temp,power_all,prev_time,t,tick)
				
			start_temp = temp_itter[-1][1]
			prev_time = temp_itter[-1][0]
			
##			print("P:",power,"\nPP:",prev_power)
#			withpower = thermalModel.step_with_power_change(prev_time, tick, power,prev_power,start_temp,prev_temp)
#			print("size",len(withpower))
#			temp_itter = temp_itter + withpower
			

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

		print("Temperature in itteration: ",temp_itter[0:100])
		temp_comp =[]
		for t in temp_itter:
			temp_comp.append((t[0],t[1][:num_comp]))
			
#		print("temp_comp",temp_comp)
#		sys.exit()
		Plot = Plotter(len(self._cluster._clus))
		Plot.plot_schedule(self._cluster)
		Plot.plot_power(time_intervals,power_over_time)
		Plot.plot_temp(temp_comp)
		
#		return wear
	       	 
		
		
	       

	def run(self):
		""" Run the simulation 
		"""
		schedulable = self.schedule(self.scheduler_type)
		time_intervals = self._cluster.get_time_intervals()
		print(time_intervals)
		num_comp = self._cluster.number_of_comps()
		alive_components =  np.ones(num_comp,dtype=bool)
#		initial_temp = np.array([[45],[45]])
#		initial_temp = np.zeros((num_comp,1),dtype=float)
		initial_temp = np.zeros((20,1),dtype=float)
		
#		print("inittempshape:",initial_temp.shape)

		tick=0.01
		thermal_model = Thermal(num_comp,tick)
		

		self.simulate_itteration(time_intervals,num_comp, alive_components, initial_temp,thermal_model,tick)
		
#		samples = np.zeros(alive_components.shape)
#		samples[alive_components] = self.model(initial_temp[alive_components]) * np.random.weibull(5.0,np.sum(alive_components))

#		wear = np.divide(1, np.floor(samples), out=np.zeros_like(samples), where=samples != 0)
#		wear = self.simulate_itteration(time_intervals, alive_components, wear,initial_temp)
			

		

