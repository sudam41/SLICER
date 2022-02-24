#!/usr/bin/env python

""" Abstract representation of a cluster containing multiple components
"""

from component import Component

class Cluster:
	""" Cluster class that contains multiple components
	"""
	def __init__(self):
		self._clus = [] 
		self._failed_comp = []
		self.names = ["Core_1,1","Core_1,2","Core_1,3","Core_2,1","Core_2,2","Core_2,3","Core_3,1","Core_3,2","Core_3,3"]
		self.enabled_comp=[]
		self.idle_power = 0.872341
	
	def __repr__(self):
		""" Representation of an Cluster object.

		:return: string - representation of this cluster object
		"""
		size = len(self._clus)
		compids = [ [ None for y in range( size) ] for x in range( size ) ]
		
		for comp in self._clus:
#			x= comp.loc[0]
#			y= comp.loc[1]
			
			compids[x][y] = comp.ID
		
		clust_str = "Cluster:\n"
		for i in range(size):
			clust_str += str(compids[i])
			clust_str += "\n"
				
#		return "Cluster:\n{}".format(compids)
		return clust_str
	
	def add_component(self, comp):
		""" Add component into the cluster
		
		:param comp:[component object] - the component to be added into this cluster.
		"""
#		self.names.append(comp.name)
		self._clus.append(comp)
		
	def number_of_comps(self):
		""" return the number of components in the cluster.
		
		:return: number of components.
		"""
		return(len(self._clus))
		
	
	@property
	def components(self):
		""" Getter function for the components instance variable.

		:return: list of all components in this cluster.
		"""
		return self._clus
		
		
	def fail_component(self,comp_id):

		for comp in self._clus:
			if comp_id == comp.ID:
				self._failed_comp.append(comp)
				self._clus.remove(comp)
				break
				
	def reset_alive_components(self):
		for i in range(len(self._clus)):
			self._clus[i].reset()
				
	def get_time_intervals(self):
		intervals = []
		for comp in self._clus:
#			print("assigned task size:",len(comp.assigned_tasks))
			for task in comp.assigned_tasks:
				intervals.append(round(task.start,4))
				intervals.append(round(task.end,4))
		
		
		intervals = list(dict.fromkeys(intervals))
#		print(intervals)
		intervals.sort()	
		return intervals 

	
	

