#!/usr/bin/env python

""" Abstract representation of an application present in embedded system design points.

    An application holds a set of tasks and a deqadline.
"""

from task import Task
from calc_energy import calc_ave_energy_task
import sys

class Application:
	def __init__(self, taskIDs, edges, execution, power, deadline):
		""" Initiaslize an application 
		
		:param taskIDs: [list] - contains the IDs of tasks (nodes on the DAG) on this application.
		:param edges: [tuple of dicts] - contains the edges of the task graph. Index of the tuple represents a target node and contains a dict where the key = source node and value = cost.
		:param execution: [dict of dicts] - contains the WCET of each task on each type of component.
		:param power: [dict of dicts] - contains the power of each task on each type of component.
		:param deadline: [float] - the deadline of the entire application.
		"""
		self._execution = execution
		self._power = power
		self._energy={}

		self._deadline = deadline
		
		self._alltasks = self.__createtasks(taskIDs, edges)
		
		
	
	def __createtasks (self, taskIDs, edges):
		""" Create task objects
		
		:param taskIDs: [list] - contains the IDs of tasks (nodes on the DAG) on this application.
		:param edges: [tuple of dicts] - contains the edges of the task graph. Index of the tuple represents a target node and contains a dict where the key = source node and value = cost.
		
		:return: [list] - contains all the task objects.
		"""
		alltasks = []
		
		for i in taskIDs:
			edge = edges[i]
			if edge == {}:
				edge  = None
			t = Task(i, dep=edge)
			
			alltasks.append(t)
			
#		for task in alltasks:
#			for dep in task.dep:
#				alltasks[dep] =  
##		print("at:",alltasks)
		return alltasks  
		
	def calc_energy(self,cluster):
		"""Calculate the average energy for the task on each component/ for each frequency"""	
		for task in self._alltasks:
			energy_comp = {}
			for comp in cluster._clus:
				energy_freq = []
				for f in range(4):
					energy_freq.append(calc_ave_energy_task(task.ID,comp.com_type,f))
				energy_comp[comp.com_type] = energy_freq
			self._energy[task.ID] = energy_comp
		
#		print("energy:",self._energy)
#		sys.exit()
		
	@property
	def execution(self):
		""" Getter function for the execution instance variable.

		:return: dict indicating the execution time for each task on this component.
		"""
		return self._execution
	
	@property
	def power(self):
		""" Getter function for the power instance variable.

		:return: dict indicating the power for each task on this component.
		"""
		return self._power	
	
	@property
	def alltasks(self):
		""" Getter function for the alltasks instance variable.

		:return: [list of task objects] - list containing all the task of the application
		"""
		return self._alltasks
		
	@property
	def deadline(self):
		""" Getter function for the deadline instance variable.

		:return: [float] - deadline of the application
		"""
		return self._deadline
		
	@deadline.setter
	def deadline(self, val):
		""" Setter function for the deadline instance variable.
		
		param cal:[float] - deadline
		"""
		if deadline < 0:
			raise ValueError("The deadline cannot be a negative value.")
		_deadline = val 
		
		
		
	
