#!/usr/bin/env python

""" Scheduler class that can schedule tasks into components
"""

class Scheduler:

	def __init__(self,application,cluster):
		""" Initialize the scheduler.

		:param application: [Applicaion object] - Application containing all the tasks to be assigned to a components.
		:param luster: [Cluster object] - Cluster containing the components.
		"""
		self._app = application
		self.cluster = cluster
		
		self.taskpool = self._app.alltasks
#		self.componentpool = self.cluster.components
		
		self.executed = []
		self.readyqueue = []
		
		self._addto_readyqueue()
		

		
		
	def _findinlist(self, taskID, list_):
		"""Finds the task object in the taskpool, readyqueue or executed list.
		
		:param taskID: [int] - task ID
		:param list_: [list] - taskpool, readyqueue or executed
		
		:return: [Task object]
		"""	

		for t in list_:
			if t.ID == taskID:
				return t

		return None

	
		
	def _addto_readyqueue(self):
		"""Updates the ready queue by adding tasks from the task pool, if they have no dependancies, into the ready queue and then removes those tasks from the task pool. 
		"""
		temp = []
	
		for t in self.taskpool:
			if t.dep == None :
				t.earliest_start = 0
				self.readyqueue.append(t)
				temp.append(t)
			else: 		
				arrivaltimes = {}
				for dep, delay in t.dep.items():

					isready = True
					deptask = self._findinlist(dep,self.executed)
					
					if deptask == None:
						isready = False
					else:
						arrivaltimes[dep] = deptask.end + delay

				if isready:
					t.earliest_start = max(arrivaltimes.values())
					self.readyqueue.append(t)
					temp.append(t)

		for t in temp:
			self.taskpool.remove(t)
	
	

	
	def _execute_task(self,task, component):
		"""Executes a task by moving it from the ready queue to the executed pool. Also updates the time to the end time of the task.
		"""

		component.time = task.end
		if component.time>self._app.deadline:
			return False,component
		self.executed.append(task)
		self.readyqueue.remove(self._findinlist(task.ID,self.readyqueue))
		
		

#		self._addto_readyqueue()
		
		
		
		#TODO: look at the queue dynnamics
		return True, component
	
	def _assign_task(self,task, component):
#			
		task.start= max(task.earliest_start,component.time)
			
		task.end = task.start+component.execution[task.ID]
		component.assigntask(task)
		return task, component
		
		
		
	def MET(self):
		
		while len(self.readyqueue)>0 or len(self.taskpool)>0:
			self._addto_readyqueue()

					
			correct_assignments =0
			for t in self.readyqueue:
				minimum = 100000
				min_comp = []
				for comp in self.cluster.components:
				
					if comp.execution[t.ID]< minimum:
						minimum = comp.execution[t.ID]
						min_comp.clear()
						min_comp.append(comp)
					elif comp.execution[t.ID] == minimum:
						min_comp.append(comp)

				best_comp = min_comp[0]

				max_idletime = best_comp.idletime(t.earliest_start)
				
				for comp in min_comp:
					idle_t =comp.idletime(t.earliest_start) 
					
					if idle_t>max_idletime:
						max_idletime = idle_t
						best_comp=comp

				
				idx = self.cluster.components.index(best_comp)
						
				assignedtask,assignedcomp = self._assign_task(t,best_comp)
				corr, execomp  = self._execute_task (assignedtask,assignedcomp) 
				
				if corr:
					self.cluster.components[idx] = execomp
					correct_assignments+=1
			
			if correct_assignments == 0:
				return False	
		return True		
					

			

