#!/usr/bin/env python


import numpy as np
from scipy import linalg
from scipy import sparse

class thermal():


	def __init__(self,start_time,t, alive_components, power ,init_temp, cond, cap, tick):
	
		self.start = start_time
		self.end = t
		self.alive = alive_components
		self.power = power
		self.init_temp = init_temp
		self.cond = cond
		self.cap = cap
		self.tick= tick
		
		self.gamma = (linalg.inv(cap)).dot(cond)
		self.psi = linalg.exppm(-gamma)
		
		I_minus_psi = sparse.identity(self.psi.shape[0]) - self.psi
		self.phi = (linalg.inv(gamma).dot(I_minus_psi)).dot(linalg.inv(cap))
		
		
	def step_without_power_change(self,start,end,tick,init_temp,prev_temp):
		
		time = np.aragne(start,stop,tick)
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
