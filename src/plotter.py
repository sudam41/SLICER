#!/usr/bin/env python
import matplotlib.pyplot as plt
import numpy as np
from cluster import Cluster

import sys

class Plotter():
	def __init__(self,no_of_comp):
		self.fig1, self.gnt = plt.subplots()
#		self.fig2, self.ax = plt.subplots(2,no_of_comp)
	
	def plot_schedule(self, cluster):
#		self.fig, self.gnt = plt.subplots()
		
		for i,comp in enumerate(cluster._clus):
#				if(alive_components[comp.ID] == True):
				for task in comp.assigned_tasks:
					print("comp:",comp.ID," task:",task.ID," start:",task.start," end:",task.end, " dep:",task.dep)
					self.gnt.broken_barh([(task.start,task.end-task.start)],(i*1.5,1),facecolors ='tab:blue',)
		self.gnt.set_yticks([0.5,2.0])
		self.gnt.set_yticklabels(['Component 0', 'Component 1'])
		self.gnt.set_xticks(np.arange(0,1,0.05))
		
#		plt.show()
#		sys.exit()
#		plt.savefig("schedule.png")
		
		
	def plot_power(self,time_intervals,power):
		no_of_components = len(power[0])
		time_length = time_intervals[-1]-time_intervals[0]
		plot_resolution = 1000
#		power_plot = np.zeros((no_of_components,int(time_length/plot_resolution)))
		plot_tick = time_length/plot_resolution
#		print("POW",power)
		for c in range(no_of_components):
			power_plot = np.zeros(plot_resolution)
			xaxis = np.arange(time_intervals[0],time_intervals[-1],plot_tick)
			time = time_intervals[0]
			for i in range(plot_resolution):
				
				for j in range(len(time_intervals)-1):
					if time>=time_intervals[j] and time<time_intervals[j+1]:
#						print("j:",j, " c:",c, " powerjc:", power[j][c])
						power_plot[i] = power[j][c]
				time = time + plot_tick
				 
			fig, powr = plt.subplots()
			print(xaxis.shape,power_plot.shape)
			self.ax[0,c].plot(xaxis,power_plot)
			self.ax[0, c].set_xlabel('Time')
			self.ax[0, c].set_ylabel('Power')
			self.ax[0, c].set_title('Component {}'.format(c))

		
#		plt.show()


	def plot_temp(self,temp):
		no_of_components = temp[0][1].size
		for comp in range(no_of_components):
			comp_temp = np.zeros(len(temp))
			xaxis = np.zeros(len(temp))
			for i,t in enumerate(temp):
				comp_temp[i] = t[1][comp]
				xaxis[i] = t[0] 
#			fig, tmp = plt.subplots()
			print("tempshape:",len(temp))
			self.ax[1,comp].plot(xaxis,comp_temp)
			self.ax[1,comp].set_xlabel('Time')
			self.ax[1,comp].set_ylabel('Temperature')
#			plt.savefig("pow_temp.png")
		plt.show()
