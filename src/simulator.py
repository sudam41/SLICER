#!/usr/bin/env python

""" This file contains most top-level functionality in order to evaluate a designpoint.

Functionalities of the simulator should be defined in the integrator.py file.
"""

import numpy as np
from electromigration import electro_migration
from scheduler import Scheduler


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
		



		
	def simulate_itteration(self, time_intervals, alive_components, wear, initial_temp):
		"""simulate a single itteration of the thermal and aging behavior

		:return: float - wear of a single itteration
		"""
		temp_itter = []
		prev_temp = initial_temp
		prev_time = time_intervals[0]
		power = np.zeros((2,2))
		
		for t in time_intervals[1:]:
			time = t - prev_time
			for comp in self._cluster._clus:
				alive_components[comp.loc[0]][comp.loc[1]] = True
				for task in comp.assigned_tasks:
					if task.start <= prev_time and task.end>= t:
						power[comp.loc[0]][comp.loc[1]] = self._app.power[task.ID][comp.com_type]
			
			temp = thermal(time, alive_components, power ,prev_temp)####CALCULATE TEMPERATURE FOR EACH TIME INTERVAL
			samples[alive_components] = self.model(temp[alive_components]) * np.random.weibull(5.0,np.sum(alive_components))
			wear[alive_components] += np.divide(1, np.floor(samples), out=np.zeros_like(samples), where=samples != 0)
		
		return wear
	       	 
		
		
	       

	def run(self):
		""" Run the simulation 
		"""
		schedulable = self.schedule(self.scheduler_type)
		time_intervals = self._cluster.get_time_intervals()
		print(time_intervals)
		alive_components =  np.zeros((2,2),dtype=bool)
		initial_temp = np.zeros((2,2),dtype=bool)
		samples = np.zeros(alive_components.shape)
		samples[alive_components] = self.model(initial_temp[alive_components]) * np.random.weibull(5.0,np.sum(alive_components))

		wear = np.divide(1, np.floor(samples), out=np.zeros_like(samples), where=samples != 0)
		wear = self.simulate_itteration(time_intervals, alive_components, wear,initial_temp)
			

		

