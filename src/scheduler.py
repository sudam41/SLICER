#!/usr/bin/env python

""" Scheduler class that can schedule tasks into components
"""
import copy
import sys
import numpy as np
from calc_energy import calc_tot_power

class Scheduler:

	def __init__(self,application,cluster,scheduler_type):
		""" Initialize the scheduler.

		:param application: [Applicaion object] - Application containing all the tasks to be assigned to a components.
		:param luster: [Cluster object] - Cluster containing the components.
		"""
		self._app = application
		self.cluster = cluster
		self.scheduler_type = scheduler_type
		
		self.taskpool = copy.deepcopy(self._app.alltasks)
#		self.componentpool = self.cluster.components
		
		self.executed = []
		self.readyqueue = []
		
		self.heft_ranks=[]
		self.allocated_comp=np.empty(len(self._app._alltasks))
		
#		self._addto_readyqueue() TODO: uncomment when not using HETF
		

		
		
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
#		print("@@@@here")
#		print("TP:",self.taskpool)
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
		"""Executes a task by moving it from the ready queue to the executed pool. 
		
		:param task: [Task object] - the task to be executed.
		:param component: [Component object] - the component that the task will be executed on.
		"""
		
		component.assigntask(task)
		component.time = task.end
		self.allocated_comp[task.ID] = component.ID
#		print("+++",component.time,"   ",self._app.deadline)
		self.executed.append(task)########
		if component.time>self._app.deadline:
			return False,component
		
		

		self.readyqueue.remove(self._findinlist(task.ID,self.readyqueue))
		
		return True, component
	
	def _assign_task(self,task, component):
		"""Assigns a task to a component. Updates the start time and the end time of the task.
		
		:param task: [Task object] - the task to be assigned.
		:param component: [Component object] - the component that the task will be assigned to.
		"""	
#		print("earlist start:",task.earliest_start)
		task.start= max(task.earliest_start,component.time)
			
		task.end = task.start+ self._app.execution[task.ID][component.com_type][component.curr_freq]#TODO add DVFS here
#		component.assigntask(task)
		#TODO:deadline
		return task
		
		
		
	def MET(self):
		"""Schedules the tasks with Minimum Execution Time Algorithm. 
		Each task in the ready queue is assigned to the component with the minimum execution time in FIFO order. 
		If two components have the same minimum value, the component with the least idle time is chosen.  
		
		:Return: [Bool] - Possibility of scheduling all the tasks in the task pool before the deadline.
		"""
		while len(self.readyqueue)>0 or len(self.taskpool)>0:
			self._addto_readyqueue()


			correct_assignments =0
			for t in self.readyqueue:
				minimum = 100000
				min_comp = []
				for comp in self.cluster.components:

					if self._app.execution[t.ID][comp.com_type][comp.curr_freq]< minimum:
						minimum = self._app.execution[t.ID][comp.com_type][comp.curr_freq]
						min_comp.clear()
						min_comp.append(comp)
					elif self._app.execution[t.ID][comp.com_type][comp.curr_freq] == minimum:
						min_comp.append(comp)

				best_comp = min_comp[0]

				max_idletime = best_comp.idletime(t.earliest_start)
				
				for comp in min_comp:
					idle_t =comp.idletime(t.earliest_start) 
					
					if idle_t>max_idletime:
						max_idletime = idle_t
						best_comp=comp

				
				idx = self.cluster.components.index(best_comp)
						
				assignedtask = self._assign_task(t,best_comp)
				corr, execomp  = self._execute_task (assignedtask,best_comp) 
				
				if corr:
					self.cluster.components[idx] = execomp
					correct_assignments+=1
			
			if correct_assignments == 0:
				return False	
		return True
		
		
	def ETF(self):
		"""Schedules the tasks with Earliest Task First Algorithm. 
		Estimated Completion Time (ECT) for each task in the ready queue for each component is calculated and the combination with the least ECT i completed
		
		:Return: [Bool] - Possibility of scheduling all the tasks in the task pool before the deadline.
		"""
		while len(self.readyqueue)>0 or len(self.taskpool)>0:
					
			self._addto_readyqueue()
			correct_assignments =0
			
			while len(self.readyqueue)>0:
				ECT_all = [] #Estimated Completion Time
				for task in self.readyqueue:
					for comp in self.cluster.components:
#						print("t:",task.ID," c:",comp.com_type," current freq:",comp.curr_freq)
						ECT = self._app.execution[task.ID][comp.com_type][comp.curr_freq] + max(task.earliest_start,comp.time)
						ECT_all.append((task,comp,ECT))
		
#				

				best_task, best_comp,tim = min(ECT_all, key=lambda x: x[2])		
#				print(best_task, best_comp)	
				
				assignedtask = self._assign_task(best_task,best_comp)		
				corr, execomp = self._execute_task(assignedtask,best_comp)
				
				idx = self.cluster.components.index(best_comp)
				
				if corr:
					self.cluster.components[idx] = execomp
					correct_assignments+=1
				else:
					break
				
			if correct_assignments == 0:
				return False	
		return True
				


########################################################################3
	def calc_ave_et(self,task):
		#average execution time for heighest frequencyy
		for comp in self.cluster._clus:
#			print("T:",task," COM:",comp.com_type," fr:", comp.curr_freq)
			ave_et = self._app.execution[task][comp.com_type][comp.curr_freq]
		return ave_et
	
	def calc_HEFT_rank(self,task):
		ave_et = self.calc_ave_et(task)
		
		succ=[]
#		print("taskpool:",self.taskpool)
		for t in self.taskpool:
#			print("task id",t.ID,"  dep:",t.dep)
			if t.dep!=None and task in t.dep:
				succ_rank =0
				for temp in self.heft_ranks:
					if temp[0]==t.ID:
						succ_rank = temp[1]
						break
				if succ_rank ==0:
#					print("here!")
					succ_rank = self.calc_HEFT_rank(t.ID)
				
#				print("t:",t.ID," task:",task," t dep:", t.dep[task]," suc rank:",succ_rank)
				succ.append(t.dep[task] + succ_rank)
		
		if len(succ)!=0:
			rank = ave_et+max(succ)
		else:
			rank = ave_et
		
#		print("t:",task," rank:",rank)
#		ranks[task] = rank
		self.heft_ranks.append((task,rank))
		return rank
	
	def calc_finish_time(self, task, component):

		freq_level = component.curr_freq
		st_for_dep = []
		if task.dep != None:	
			for dep in task.dep:
				com_time = 0
				pot_start_time = 0
#				print("task: ",task)
#				print("executed: ",self.executed)
#				print("component.assigned_tasks",component.assigned_tasks)
				if (any(asgn_task.ID == dep for asgn_task in component.assigned_tasks)==False):
					com_time = task.dep[dep]
				deptask = self._findinlist(dep,self.executed)
#				print("deptask.end:",deptask.end,"  com_time:",com_time)
				pot_start_time = deptask.end + com_time
#				print("pot_start_time:",pot_start_time)
		
				#check if component free at the potential start time
				assign = False
				while assign == False:
					assign = True
					for t in component.assigned_tasks:
						if t.start<= pot_start_time and t.end>pot_start_time:
							pot_start_time = t.end
							assign = False
							break
					
		#			start_time = pot_start_time
					pot_finish_time = pot_start_time + self._app.execution[task.ID][1][freq_level]
				
					for t in component.assigned_tasks:
						if t.start<= pot_finish_time and t.start>=pot_start_time:
							pot_start_time = t.end
							assign = False
							break
				
					st_for_dep.append(pot_start_time)
				
			start_time = max(st_for_dep)
		else:
			start_time = 0
		finish_time = start_time + self._app.execution[task.ID][component.com_type][freq_level]
#					start_time = pot_start_time
#					finish_time = pot_finish_time
		 	
#		print("T:",task.ID," C:",component.ID," ST:",start_time," FT:",finish_time)
		return start_time,finish_time
	
	def find_exit_task(self):
		#find exit task
		lastfinish = 0
		exit =0
		for task in self.executed:
			if task.end>lastfinish:
				lastfinish = task.end
				exit = task.ID
		return exit, lastfinish
		
		
	def HEFT(self):
		
		self.calc_HEFT_rank(0)
		self.heft_ranks.sort(key = lambda x:x[1], reverse=True)
#		print(self.heft_ranks)
		
		for t in self.heft_ranks:
			taskID = t[0]
#			print("tid:",taskID)
			self.readyqueue.append(self.taskpool[taskID])
	
#		for task in self.readyqueue:
			
#		print("RQ:",self.readyqueue)
		readyqueue_copy = copy.deepcopy(self.readyqueue)
		for task in readyqueue_copy:
			finish_times = []
			start_times = []
#			print("task:",task.ID)
			for comp in self.cluster._clus:
				start_time,finish_time = self.calc_finish_time(task,comp)
				finish_times.append(finish_time)
				start_times.append(start_time)
				
			min_ft = min(finish_times)
			best_comp_ID = finish_times.index(min_ft)
			self.allocated_comp[task.ID]=best_comp_ID
#			print("best comp:",best_comp_ID)
			task.start = start_times[best_comp_ID]
			task.end = finish_times[best_comp_ID]
			
			self._execute_task(task,self.cluster._clus[best_comp_ID])
		
		exittask, lastfinish = self.find_exit_task()
#		#find exit task
#		lastfinish = 0
#		for task in self.executed:
#			if task.end>lastfinish:
#				lastfinish = task.end
		
#		print("SL(G):",lastfinish)
		if self.scheduler_type == "HEFT":
			if lastfinish <= self._app._deadline:
				return True
			else:
				return False
		else:
			return lastfinish
		
		
	def DNDS(self):
#		print("---------------------------- DNDS START ---------------------------------------")
		self.heft_ranks.clear()
		self.executed.clear()
		self.readyqueue.clear()
		for c in self.cluster._clus:
			c.reset()
			
#		print("\n#####exe:",self.executed,"\n")
		HEFT_makespan = self.HEFT()
#		print("\n@@First HEFT Done, makespan =",HEFT_makespan," @@\n")
		DNDS_taskpool = copy.deepcopy(self.executed)
#		print("\n#####exe:",self.executed,"\n")
		
		
		#obtain the energy consumption for each task at max frequency on each component
		maxfreq_energy = []
		for task in self.taskpool:
			energy = []
			for c in self.cluster._clus:
				energy.append((c.ID,self._app._energy[task.ID][c.com_type][c.curr_freq]))
			
			energy.sort(key = lambda x:x[1]) #TODO: Add execution time here
			maxfreq_energy.append(energy)
#		print("\n@@Energy Consumption:",maxfreq_energy," @@\n")
			
		#determine quality of allocation for each task
		task_QoA = np.zeros(len(self.taskpool))
		for task in self.taskpool:
#			for energy_tasks in maxfreq_energy[task.ID]:
#				print("ET",energy_tasks)
			for i,comp in enumerate(maxfreq_energy[task.ID]):
				if comp[0] == self.allocated_comp[task.ID]:
#					print("----",comp,"----",)
					task_QoA[task.ID] = i+1
#		print("\n@@QoA:",task_QoA," @@\n")
		
		level = len(self.cluster._clus)
		
#		print("self.rq:",self.readyqueue )
		#reset queues
		self.readyqueue.clear()
		self.executed.clear()
		for c in self.cluster._clus:
			c.reset()
#		print("Heft Rank:",self.heft_ranks)
#		#recalculating heft ranks
#		self.calc_HEFT_rank(0)
#		self.heft_ranks.sort(key = lambda x:x[1], reverse=True)
#		print("after recalc:",self.heft_ranks)
		
#		for t in self.heft_ranks:
#			taskID = t[0]
#			print("tid:",taskID)
#			self.readyqueue.append(DNDS_taskpool[taskID])
#		print("dnds tp:",DNDS_taskpool )
#		print("self.rq:",self.readyqueue )
		self.readyqueue = copy.deepcopy(DNDS_taskpool)
#		print("self.rq:",self.readyqueue )
		rq_copy = copy.deepcopy(self.readyqueue)
		
		makespan = HEFT_makespan
		new_allocation = copy.deepcopy(self.allocated_comp)
		old_allocation = copy.deepcopy(self.allocated_comp)
#		print("level:",level," HEFT_makespan:",HEFT_makespan)
		while level>1 and makespan < self._app._deadline:
			waiting_opt = []
			for task,QoA in enumerate(task_QoA):
				if QoA == level:
					waiting_opt.append(self._findinlist(task,DNDS_taskpool))
			
			for nj in waiting_opt:
#				print("\nlevel:",level," task in waiting:",nj.ID)
				#reset for next itteration	
				self.readyqueue.clear()
				self.readyqueue = copy.deepcopy(rq_copy)
				self.executed.clear()
				for c in self.cluster._clus:
					c.reset()
			
				rq = copy.deepcopy(self.readyqueue)
#				print("rq:",rq)
				for ni in rq:
#					print("ni:",ni.ID,"  nj:",nj.ID)
					if ni.ID == nj.ID:
#						print("maxfreq energy:",maxfreq_energy[nj.ID])
						new_allocation[nj.ID] = maxfreq_energy[nj.ID][0][0]
					
#					print("new allocation:",new_allocation," old:",old_allocation)
#					print("clus:",len(self.cluster._clus))
					
					compID = int(new_allocation[ni.ID])
					comp = self.cluster.find_alive_component(compID)
					
					start_time ,finish_time = self.calc_finish_time(ni,comp)
					ni.start = start_time
					ni.end = finish_time
					
					self._execute_task(ni,comp)
					
				exittask,makespan = self.find_exit_task()
#				print("msp:",makespan)
				if makespan>self._app._deadline:
#					print("%%%%msp:",makespan," task:",nj.ID)
#					print("old allocatioin:",old_allocation," new allocation:",new_allocation)
					new_allocation[nj.ID] = copy.deepcopy(old_allocation[nj.ID])#self.allocated_comp[nj.ID]
					self.allocated_comp[nj.ID] = copy.deepcopy(old_allocation[nj.ID])
#					print("old allocatioin:",old_allocation," new allocation:",new_allocation)
					
					self.readyqueue.clear()
					self.readyqueue = copy.deepcopy(rq_copy)
					self.executed.clear()
					for c in self.cluster._clus:
						c.reset()
					for ni in rq:
						compID = int(new_allocation[ni.ID])
						comp = self.cluster.find_alive_component(compID)
						
						start_time ,finish_time = self.calc_finish_time(ni,comp)
						ni.start = start_time
						ni.end = finish_time
						
						self._execute_task(ni,comp)
					exittask,makespan = self.find_exit_task()
#					sys.exit()
				
					
			level -=1
		
##		print("old allocatioin:",old_allocation," new allocation:",new_allocation)
#		print("exe:",self.executed)
#		print("taskpool:",self.taskpool)
		if makespan == 0:
			print("ms:",makespan)
			sys.exit()
#		print("makespan = ",makespan)	
#		print("___________________________________ DNDS END ______________________________________")
		if self.scheduler_type == "DNDS":
			if makespan <= self._app._deadline:
				return True
			else:
				return False
		else:
			return makespan
#		sys.exit()
		
		
	def calc_component_rank(self): 
		rank = []
#		print("XX")
		for comp in self.cluster._clus:
			totpower=0
			totsamples=0
			for tID, alloc in enumerate(self.allocated_comp):
#					task = self._findinlist(tID,self.taskpool)
#				print("tID:",tID," alloc:",alloc)
				if alloc == comp.ID:
					power, samples = calc_tot_power(tID,comp.com_type,comp.curr_freq)
					totpower+=power
					totsamples+=samples
			
			if totsamples ==0:
				avepower = 0
			else:
				avepower = totpower/totsamples 
		
			rank.append((comp.ID,avepower))
			
		rank.sort(key = lambda x:x[1], reverse=True)
		return rank
#		print("rank:",rank)
		
		
	def DWDS(self):
		
#		print("DWDS CLUS: ", len(self.cluster._clus))
		for comp in self.cluster._clus:
			comp.curr_freq = 3
#			print("c:",comp.ID," fq:",comp.curr_freq )
		DNDS_makespan = self.DNDS()
#		print("\n@@ First DNDS done!\n")
		best_freq=False
		x=0
		while DNDS_makespan <= self._app._deadline and best_freq==False:
			x+=1
			comprank = self.calc_component_rank()
#			print("comprank:",comprank)
#			if x==1:
#				sys.exit()
#			comp = self.cluster._clus[0]
#			print("comp:",comp.ID," comp.curr_freq:",comp.curr_freq)
#			sys.exit()
			best_freq = True
			for compr in comprank:
				compID = int(int(compr[0]))
				comp = self.cluster.find_alive_component(compID)

#				print("comp:",comp.ID," comp.curr_freq:",comp.curr_freq)
#				sys.exit()
				print(best_freq)
				comp.curr_freq-=1
#				print("c:",comp.ID," freq:",comp.curr_freq)
				if comp.curr_freq>=0:
					best_freq=False
#					comp.curr_freq-=1
#					print("c:",comp.ID," freq:",comp.curr_freq)
					DNDS_makespan = self.DNDS()
#					print("^^^^^Makespan:",DNDS_makespan)	
					if DNDS_makespan <= self._app._deadline:
#						print("$$$$$ Break $$$$$$$")
						break
					else:
						comp.curr_freq+=1
#						print("c:",comp.ID," freq changed to :",comp.curr_freq)
				else:
					comp.curr_freq+=1
		
#		print("*********************before final dnds********************")
		DNDS_makespan = self.DNDS()
#		for comp in self.cluster._clus:
#			print("c:",comp.ID," fq:",comp.curr_freq," bf:",best_freq )
#		print("Final Makespan:",DNDS_makespan)	
		
		if DNDS_makespan <= self._app._deadline:
			return True
		else:
			return False

