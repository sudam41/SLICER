#!/usr/bin/env python


import numpy as np
from scipy import linalg
from scipy import sparse
from calc_thermal_parameters import Thermal_Parameters
class Thermal():


	def __init__(self, no_of_comp):
	
		self.parameters = Thermal_Parameters()	
		self.no_of_comp = no_of_comp
		
		self.parameters.getThermalParameters()
		self.cap = self.parameters.cap[0:no_of_comp,0:no_of_comp]
		self.cond = self.parameters.cond[0:no_of_comp,0:no_of_comp]
		
		self.gamma = (linalg.inv(self.cap)).dot(self.cond)
		self.psi = linalg.expm(-self.gamma)
		
		I_minus_psi = sparse.identity(self.psi.shape[0]) - self.psi
		self.phi = (linalg.inv(self.gamma).dot(I_minus_psi)).dot(linalg.inv(self.cap))
		
		
	def step_without_power_change(self,start,end,tick,init_temp,prev_temp):
		
		time = np.arange(start,end,tick)
		Tk_minus_1 = prev_temp
		Tk = init_temp
		temp = [] 
		for t in time[1:]:
			Tk_plus_1 = (self.psi + sparse.identity(self.psi.shape[0])).dot(Tk) - self.psi.dot(Tk_minus_1)
			Tk_minus_1 = Tk
			Tk = Tk_plus_1
			temp.append({t:Tk_plus_1})
		return temp
			
	def step_with_power_change(self,start, tick, next_power,cur_power,init_temp,prev_temp):
		Tk_minus_1 = prev_temp
		Tk = init_temp
		
		Pk = cur_power
		Pk_plus_1 = next_power
		
		Tk_plus_1 = (self.psi + sparse.identity(self.psi.shape[0])).dot(Tk) - self.psi.dot(Tk_minus_1) + self.phi.dot(Pk_plus_1 - Pk)
		
		return {start+tick : Tk_plus_1}
