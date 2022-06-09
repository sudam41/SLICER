#!/usr/bin/env python

""" Abstract representation of a task present in embedded system design points.


"""


class Task:
	def __init__(self, ID, start=None, end=None, dep=None, succ=None, earliest_start=None, comp=None):
		""" Initialize a task that can be mapped to a component.

		:param ID: [inteager] - Task ID.
		:param dep: [dict] - contains the IDs of tasks that this task is dependant on as the key and the delay for each depentant task as the value.
		:param start: [float] - the start time of the task.
		:param end: [float] - the end time of the task.

		"""
#		assert start >= 0, "start time has to be possitive."
#		assert end > 0, "end time has to be greater than 0"

		self.ID = ID
		self.dep = dep
		self.succ=succ
		self.start = start
		self.end = end
		self.earlliest_start = earliest_start
		self.allocated_comp=comp
		
        
	
	def __repr__(self):
		""" Representation of an task object.

		:return: string - representation of this task object
		"""
		return "ID:{}|start:{}|end:{}|dep:{}".format(self.ID, self.start, self.end, self.dep)



	@property    
	def dep(self):
		""" Getter function for the dependancies instance variable.

		:return: [dict] - contains the IDs of tasks that this task is dependant on as the key and the delay for each depentant task as the value.
		"""
		return self._dep
		
	@dep.setter
	def dep(self, val):
		""" Setter function for the dep instance variable.
		
		:param val: [dict] - contains the IDs of tasks that this task is dependant on as the key and the delay for each depentant task as the value. 
		"""
		if val != None:
			if type(val) is not dict:
				
				raise TypeError("dependancy should be of type dict")
			
			
			for depId, delay  in val.items():
				if delay <0 :
					raise ValueError("Delay between task {} and task {} cannot be a negative value.".format(self.ID, depId))
					
		self._dep = val
		
				
		

	@property    
	def start(self):
		""" Getter function for the start time instance variable.

		:return: [float] -  the start time for this application.
		"""
		if self._start != None:
			start = round(self._start,4)
		else:
			start = self._start
		return start

	@start.setter
	def start(self, val):
		""" Setter function for the start time instance variable.
		
		param val:[float] -  start time
		"""
		if val!=None and val<0:
			raise ValueError("The start time has to be possitive.")
		self._start = val 

	@property    
	def end(self):
		""" Getter function for the end time instance variable.

		:return: [float] - the end time for this application.
		"""
		if self._end != None:
			end = round(self._end,4)
		else:
			end = self._end
		return end

	@end.setter
	def end(self, val):
		""" Setter function for the start time instance variable.
		
		param val:[float] -  end time
		"""
		if val!=None and val<=0:
			raise ValueError("The end time has to be possitive.")
		self._end = val 
    
    	
