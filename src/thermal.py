#!/usr/bin/env python


import numpy as np
from scipy import linalg
from scipy import sparse
from calc_thermal_parameters import Thermal_Parameters
from test import Eigendata

import sys
class Thermal():


	def __init__(self, no_of_comp,tick):
	
		self.parameters = Thermal_Parameters()	
		self.no_of_comp = no_of_comp
		
		self.parameters.getThermalParameters()
		self.cap = self.parameters.cap#[0:no_of_comp,0:no_of_comp]
		self.cond = self.parameters.cond#[0:no_of_comp,0:no_of_comp]
		print("cond size:",self.cond.shape)
		print("cap size:",self.cap.shape)
		
		self.gamma = (linalg.inv(self.cap)).dot(self.cond)
#		print("gamma_simu:",self.gamma)
		
		self.psi_all = linalg.expm(-self.gamma*tick)
		
		E= Eigendata()
		cond_inv_eig,psi_eig = E.get_values()
		
		self.psi_all = psi_eig
		
#		print("psi shape",self.psi_all.shape)
#		sys.exit()
		I_minus_psi = sparse.identity(self.psi_all.shape[0]) - self.psi_all
		
		self.phi_all = (linalg.inv(self.gamma).dot(I_minus_psi)).dot(linalg.inv(self.cap))
#		print("psi:",self.psi_all," psi shape:",self.psi_all.shape)
#		print("cond:", linalg.inv(self.cond))

		
		
#		print("psi_diff:",psi_eig-self.psi_all)
		

#		sys.exit()
#		self.psi = psi_all[0:no_of_comp,0:no_of_comp]
#		self.phi = phi_all[0:no_of_comp,0:no_of_comp]

#		print("psi_simu:",self.psi)
#		print("phi_simu:",self.phi)
		
		
	def step_without_power_change(self,start,end,tick,init_temp,prev_temp):
		
		print("step without power change!")
		time = np.arange(start,end,tick)
		
#		print("prevtemp",prev_temp)
		Tk_minus_1 = np.copy(prev_temp)
		Tk = np.copy(init_temp)
		temp = [] 
		print("psi:",self.psi)
		for t in time[1:]:
			
			print("Tk",Tk)

#			print("Tk-1.shape:",Tk_minus_1.shape)
			print("Tk-1:",Tk_minus_1)
			Tk_plus_1 = np.matmul((self.psi + sparse.identity(self.psi.shape[0])),Tk) - np.matmul(self.psi,Tk_minus_1)

			print("Tk+1:",Tk_plus_1)
			Tk_minus_1 = np.copy(Tk)
			Tk = np.copy(Tk_plus_1)
			temp.append((t,Tk_plus_1))
			
#			if t==time[3]:
#				sys.exit()
		return temp
			
	def step_with_power_change(self,start, tick, next_power,cur_power,init_temp,prev_temp):
		print("step with power change!")
		Tk_minus_1 = prev_temp
		Tk = init_temp
		
		Pk = cur_power
		Pk_plus_1 = next_power
		
		print("Pk",Pk)
		print("Pk-1:",Pk_plus_1)
		print("powchange:",Pk_plus_1 - Pk)
		print("Tk",Tk)
		print("Tk-1:",Tk_minus_1)
		print("phi:",self.phi)
		
		
#		print("SHAPES: ",Tk_minus_1.shape,Tk.shape,Pk.shape,Pk_plus_1.shape)
#		print("power change:",Pk_plus_1-Pk)
		Tk_plus_1 = ((self.psi + sparse.identity(self.psi.shape[0])).dot(Tk) - self.psi.dot(Tk_minus_1)) + self.phi.dot(Pk_plus_1 - Pk)
		print("Tk+1:",Tk_plus_1)
#		sys.exit()
		return [(start+tick , Tk_plus_1)]
		
		
	def step_all(self, curr_temp, next_pow,start,end,tick):
		Tk = np.copy(curr_temp)
		
		pk_plus_one = np.copy(next_pow)
		
		time = np.arange(start,end,tick)
		
		temp_all = []
		for t in time[1:]:
			Tk_plus_one = self.psi_all.dot(Tk) + self.phi_all.dot(pk_plus_one)
			
			temp_all.append((t,Tk_plus_one))
			Tk = np.copy(Tk_plus_one)
		
		return temp_all
		
#	def step_with_power_change_s(self,start, end, tick, next_power,cur_power,init_temp,prev_temp):
#		print("step with power change s!")
#		
#		time = np.arange(start,end,tick)
#		
#		Tk_minus_1 = prev_temp
#		Tk = init_temp
#		
#		Pk = cur_power
#		Pk_plus_1 = next_power
#	
#		temp = []
##		print("SHAPES: ",Tk_minus_1.shape,Tk.shape,Pk.shape,Pk_plus_1.shape)
##		print("power change:",Pk_plus_1-Pk)

#		for t in time[1:]:
#			Tk_plus_1 = ((self.psi + sparse.identity(self.psi.shape[0])).dot(Tk) - self.psi.dot(Tk_minus_1)) + self.phi.dot(Pk_plus_1 - Pk)
#			Tk_minus_1 = Tk
#			Tk = Tk_plus_1
#		return [(start+tick , Tk_plus_1)]
