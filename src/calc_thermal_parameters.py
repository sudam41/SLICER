#!/usr/bin/env python
import numpy as np

C_FACTOR = 0.333
class Thermal_Parameters():
	def __init__(self, config, floorplan):
		self.config = config
		self.floorplan = floorplan
#		print(len(floorplan))
		
	def calcCapacitance(self):
		cond = np.zeros((len(self.floorplan),len(self.floorplan)))
		for i,unit in enumerate(self.floorplan):
			cond[i,i] = self.config["p_chip"] * self.config["t_chip"]* unit[1] *unit[2] * C_FACTOR
			
		print(cond)
		return cond
		
	def calcConductance(self):
		Gx = np.zeros(len(self.floorplan))
		Gy = np.zeros(len(self.floorplan))
		
		for i,unit in enumerate(self.floorplan):
			Gx[i] = 1/((unit[1]/2)/(self.config["k_chip"] * unit[1] *unit[2]))
			Gy[i] = 1/((unit[2]/2)/(self.config["k_chip"] * unit[1] *unit[2]))
			
		
