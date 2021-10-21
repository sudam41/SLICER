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

		for comp in _clus:
			if comp_id == comp.ID:
				self._failed_comp.append(comp)
				self._clus.remove(comp)
				break
				
	def get_time_intervals(self):
		intervals = []
		for comp in self._clus:
			for task in comp.assigned_tasks:
				intervals.append(task.start)
				intervals.append(task.end)
		
		
#		intervals = list(dict.fromkeys(intervals))
#		print(intervals)
		intervals.sort()	
		return intervals 

	
	

