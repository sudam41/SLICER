#!/usr/bin/env python

""" Contains all logical operations that are required for the ageing of components in the simulation

Ageings are stored as a 2D numpy float array.
"""

import numpy as np

from electromigration import electro_migration


class Ageing():
	""" Contains all logical operators based on the aging of components.""" 
	def __init__ (self, model=electro_migration):
		self.model = model
		self.beta = 2
		self.totTime=0
		
	def _reliability(self, time, temp):
		R = np.exp(-np.power(np.divide(time,self.model(temp)), self.beta))
#		print("temp:",self.model(temp)," rel:",R)
		return R
		
	def _time(self,rel,temp):
		T = self.model(temp)* np.power(-np.log(rel),(1/self.beta))
#		print("time:",T)
		return T
		
	def calc_time_until_failure(self, steady_temp, alive_comp, period, current_rel):
		curr_period = self.totTime/period
		curr_map = 0
		no_of_intervals = len(steady_temp)
#		curr_spare_period =   period - (self.totTime % period)
		curr_spare_period = (np.floor(curr_period)+1-curr_period)*period
		
		numb_alive = np.count_nonzero(alive_comp)
		
		t=np.zeros(len(alive_comp))
#		time = np.ones(len(alive_comp))*np.inf
		cR = np.copy(current_rel[alive_comp])
		
		elapsedT = self._time(cR,steady_temp[curr_map][alive_comp])
		testR = self._reliability(elapsedT + curr_spare_period, steady_temp[curr_map][alive_comp])
#		print("curr_spare_period",curr_spare_period,"  curr_spare_period1",curr_spare_period1)
		randval = np.random.random_sample(numb_alive)
		print("rand val:",randval)
		randrel = randval * current_rel[alive_comp]
		
		j=-1
		for i in range(len(alive_comp)):
			if alive_comp[i] == True:
				j+=1
			else:
				continue
				
			first_itter = True
			while testR[j]>randrel[j]:
				if first_itter == True:
					t[i] = curr_spare_period
					first_itter = False
				else:
					t[i]+=period
				
#				print("t[{}]:".format(i),t[i]  )	
				cR[j] = testR[j]
				
				curr_map = (curr_map+1)%no_of_intervals
				
				elapsedT[j] = self._time(cR[j],steady_temp[curr_map][alive_comp][j])
				testR[j] = self._reliability(elapsedT[j] + period, steady_temp[curr_map][alive_comp][j])
			
#				print("testR[j]:",testR[j]," > "," randrel[j]",randrel[j])
				
			if (cR[j]>randrel[j]):
				lastElapsedT = self._time(randrel[j],steady_temp[curr_map][alive_comp][j])
				eqT = self._time(cR[j],steady_temp[curr_map][alive_comp][j])
				
				t[i] += lastElapsedT-eqT
				
		
		t[~np.array(alive_comp)] = np.inf
			
		minIdx = np.argmin(t)		

		self.totTime +=t[minIdx]
		
		print("t:",t, " tot time:",self.totTime)
		
		
		#TODO:check for min cores
		alive_comp[minIdx] = False
		
		curr_period = (self.totTime-t[minIdx])/period
		curr_map = int(np.floor(curr_period)%no_of_intervals)
		curr_spare_period = (np.floor(curr_period)+1-curr_period)*period
		
		elapsedT = 0
		tmpElapsedT = np.copy(curr_spare_period)
		
		eqElapsedT = self._time(current_rel[alive_comp],steady_temp[curr_map][alive_comp])
		
		tmpR = self._reliability(eqElapsedT+curr_spare_period,steady_temp[curr_map][alive_comp])
		
		while tmpElapsedT < t[minIdx]:
			current_rel[alive_comp] = tmpR
			elapsedT = np.copy(tmpElapsedT)
			
			tmpElapsedT += period
			
			curr_map = (curr_map+1)%no_of_intervals
			
			eqElapsedT = self._time(current_rel[alive_comp],steady_temp[curr_map][alive_comp])
			
			tmpR = self._reliability(eqElapsedT+period,steady_temp[curr_map][alive_comp])
			
		lastDelta = t[minIdx]-elapsedT
		eqElapsedT = self._time(current_rel[alive_comp],steady_temp[curr_map][alive_comp])
		
		tmpR = self._reliability(eqElapsedT+lastDelta,steady_temp[curr_map][alive_comp])
		print("time:",eqElapsedT+lastDelta)
		print("alive:",alive_comp)
		current_rel[alive_comp] = tmpR
		
		print("curr rel:",current_rel)
		
#		return alive_comp,
		
		
		
	
A = Ageing()
temp = np.array([[45,10,12],[15,7,12],[12,63,12],[82,51,12],[49,32,12]])
alive= [True,False,True]
period = 0.5
currR = np.array([1.0,1.0,1.0])
print(currR)
A.calc_time_until_failure(temp,alive,period,currR)

#rel = A._reliability(3.50353192, 15)
#time = A._time(rel,temp)


