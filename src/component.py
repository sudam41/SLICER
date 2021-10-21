#!/usr/bin/env python

""" Abstract representation of a component present in embedded system design points.

"""


class Component:
	"""Represents a computing component within a design point."""

	def __init__(self, ID, com_type, location, width,height, self_temp=50, time=0):
		""" Initialize a component representing a CPU.

		:param ID: [Inteager] - ID of this component.
		:param com_type: [Inteager] - Type of this component.
		:param location: (x, y) tuple of the location of the component on the grid.
				 Each component in a designpoint should have a unique location
		:param self_temp: temperature of cpu upon 100% utilization
		:parm time: [float] - time that the last task executed on this component 
		"""
		#        assert comp_capability >= 0, "Power_capacity has to be a non-negative integer"
		#        assert location[0] >= 0, "Location indices have to be non-negative"
		#        assert location[1] >= 0, "Location indices have to be non-negative"
		#        assert self_temp > 0, "Max_temp has to be greater than 0"

		self.ID = ID
		self.com_type = com_type
		self._self_temp = self_temp
		self.loc_botleft = location
		self.loc_topright = (location[0]+width,location[1]+height)
		self._time = time
		self.assigned_tasks = []
		self.alive = True
		

	def __repr__(self):
		""" Representation of an Component object.

		:return: string - representation of this Component object
		"""
		return "Id: {}\nType: {}\nLoc: {} | {}".format(self.ID, self.com_type, self.loc_botleft,self.loc_topright)
#		return "component Id: {}".format(self.ID)
		


#	@property
#	def execution(self):
#		""" Getter function for the execution instance variable.

#		:return: dict indicating the execution time for each task on this component.
#		"""
#		return self._execution
#		
#	@execution.setter
#	def execution(self, val):
#		""" Setter function for the execution instance variable.
#		:param val: [float] - execution time
#		"""
#		if type(val) is not dict:
#			raise TypeError("execution should be of type dict")
#		
#		for taskid, time in val.items():
#			
#			if type(taskid) is not int:
#				raise TypeError("Task Id should be of type inteager")
#				
##			if type(time) is not float:
##				raise TypeError("Execution time should be of type float")
##				
#			if time <= 0 :
#				raise ValueError("Execution time of task {} on component {} has to greater than 0".format(taskid,self.ID))	
#		
#		self._execution= val	


#	@property
#	def power(self):
#		""" Getter function for the power instance variable.

#		:return: dict indicating the power for each task on this component.
#		"""
#		return self._power
#		
#	@power.setter
#	def power(self, val):
#		""" Setter function for the power instance variable.
#		:param val:[float] - power
#		"""
#		if type(val) is not dict:
#			raise TypeError("power should be of type dict")		
#		
#		for taskid,powr in val.items():
#			 
#			if type(taskid) is not int:
#				raise TypeError("Task Id should be of type inteager")
#				
##			if type(powr) is not float:
##				raise TypeError("Power should be of type float")
##				
#			if powr <= 0 :
#				raise ValueError("power of task {} on component {} has to greater than 0".format(taskid,self.ID))	
#		
#		self._power= val


	@property
	def time(self):
		""" Getter function for the time instance variable.

		:return: [float] - time that the last task executed on this component.
		"""
		return self._time


	@time.setter
	def time(self,val):
		""" Setter function for the time instance variable.
		
		:param val:[float] - time that the last task executed on this component.
		"""	
		if val < 0 :
			raise ValueError("time variable cannot be set to a neagative value")	
		#TODO make sure that time does not redudce
		self._time= val	
		


	@property
	def max_temp(self):
		""" Getter function for the max_temp instance variable.

		:return: integer indicating the max temperature for this component.
		"""
		return self._self_temp


	@property
	def loc(self):
		""" Getter function for the max_temp instance variable.

		:return: integer tuple (x, y) indicating the position of this component.
		"""
		print("***HERE!")
		return self.loc_botleft
		
	def assigntask(self,task):
		"""Assigns a task to this component.
		
		:param task: [Task object] - the task to be assigned
		"""
	
		self.assigned_tasks.append(task)
		
	def idletime(self,endtime):
		"""Returns the component's idle time until a given point
		
		:parm endtime: [float] - the idle time is calculated from the start (i.e. time = 0) until this point.
		:return [float] - total idel time on the component.
		"""
		total_exe_time = 0
		for t in self.assigned_tasks:
			if t.end< endtime:
				total_exe_time += t.end-t.start
			elif t.start< endtime:
				total_exe_time += endtime
		
		return endtime - total_exe_time
		
	
		
