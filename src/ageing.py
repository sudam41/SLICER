#!/usr/bin/env python

""" Contains all logical operations that are required for the ageing of components in the simulation

"""

import numpy as np
import matplotlib.pyplot as plt
import sys
import copy

from electromigration import electro_migration


class Ageing():
	""" Contains all logical operators based on the aging of components.""" 
	def __init__ (self, data,interval,model=electro_migration):
		self.model = model
		self.beta = 2
		self.totTime=0
		self.data = data
		self.interval = interval
		
	def _reliability(self, time, alpha):
		R = np.exp(-np.power(np.divide(time,alpha), self.beta))
#		print("temp:",self.model(temp)," rel:",R)
		return R
		
	def _time(self,rel,alpha):
#		print("alpha: ",alpha)
		T = alpha* np.power(-np.log(rel),(1/self.beta))
#		print("time:",T)
		return T
		
	def _avarage_ageing_rate(self,time_intervals,temp,alive_comp):
		tot_time= temp[0][-1]-temp[0][0]
#		print("total time:",tot_time)
#		print("$ti:",time_intervals)
		num_comp = len(alive_comp)
#		print("TI:",time_intervals)
#		sys.exit()
		age_rate=np.zeros((num_comp,len(time_intervals)-1))
		for i,t in enumerate(time_intervals[1:]):
			interval_time = t-time_intervals[i]
			idx = np.where(temp[0]<t,temp[0],0)
			idx = np.where(idx>time_intervals[i])
#			print("time_intervals[i]:",time_intervals[i],"  t:",t)
#			print("temp:",temp[0][30000:30010])
#			if idx[0].size ==0:
#				print("time_intervals[i]:",time_intervals[i],"  t:",t)
#				print("temp:",temp[0][30000:30010])
#				sys.exit()
#			print("%%%idx:",idx)
			for comp in range(num_comp):
#				print("np.average(temp[comp+1][idx]):",np.average(temp[comp+1][idx]),"  idx:",idx)
				if alive_comp[comp] == True:
					age_rate[comp][i] = interval_time/self.model(np.average(temp[comp+1][idx])) 
#					print("MTTF:",self.model(np.average(temp[comp+1][idx]))*0.88623) 
		
#		print("age rate:",age_rate)
		alpha=np.empty(num_comp)
		alpha[:] =np.NaN
		for comp in range(num_comp):
			if alive_comp[comp] == True: 
#				print("@Here","agerate:",age_rate)
				alpha[comp] = tot_time/np.sum(age_rate[comp])
#				print("@lpha:",alpha)
		return alpha
		
	def _average_ageing_rate_uniform(self,temp,start,stop,interval,alive_comp):
		tot_time = stop - start
		num_comp = len(alive_comp)
		age_rate_max=np.zeros((num_comp,int(tot_time/interval)+1))
		age_rate_ave=np.zeros((num_comp,int(tot_time/interval)+1))
		
		time = start
		i=0
		while time<stop:
			idx = np.where(temp[0]<(time+interval),temp[0],0)
			idx = np.where(idx>time)
#			print("i:",i," time:",time," stop:",stop)
			for comp in range(num_comp):
				if alive_comp[comp] == True:
					age_rate_max[comp][i] = interval/self.model(np.amax(temp[comp+1][idx]))
					age_rate_ave[comp][i] = interval/self.model(np.average(temp[comp+1][idx]))
					
			time += interval
			i+=1
			
		alpha_max=np.empty(num_comp)
		alpha_max[:] =np.NaN
		
		alpha_ave=np.empty(num_comp)
		alpha_ave[:] =np.NaN
		for comp in range(num_comp):
			if alive_comp[comp] == True: 
#				print("@Here","agerate:",age_rate)
				alpha_max[comp] = tot_time/np.sum(age_rate_max[comp])
				alpha_ave[comp] = tot_time/np.sum(age_rate_ave[comp])
#				print("@lpha:",alpha_max)
		return alpha_max, alpha_ave
			
	def fail_component(self, current_rel, alive_comp, alpha):
		numb_alive = np.count_nonzero(alive_comp)
		randval = np.random.random_sample(len(alive_comp))
		randrel = randval * current_rel
#		print("random:",randrel)
		
		t = self._time(randrel,alpha)
		eqT = self._time(current_rel,alpha)
#		print("&&&&&&&&&t:",t,"eqT:",eqT)
		t=t-eqT
		t[~np.array(alive_comp)] = np.inf
		
		minIdx = np.argmin(t)		

		self.totTime +=t[minIdx]
		alive_comp[minIdx] = False
#		print("AC: ",alive_comp)
		
		current_rel = self._reliability(t[minIdx]+eqT,alpha)
#		current_rel[minIdx]=0
		fail_time = t[minIdx]
		return alive_comp, current_rel,fail_time
	
	def run(self, alive_comp, current_rel, time_intervals,temp,num_comp,p_fail_time):
#		print("time int:",time_intervals, "  temp:",temp)
#		alpha_ti = self._avarage_ageing_rate(time_intervals,temp,alive_comp)
		temp[0] = temp[0]/3600
		
		alpha_max,alpha_ave = self._average_ageing_rate_uniform(temp,temp[0][0],temp[0][-1],self.interval/3600,alive_comp) 
#		print("\n:::AC:",alive_comp, "alpha_max:",alpha_max)
		
		
#		fig2,ax = plt.subplots()
#		for i,a in enumerate(alpha[alive_comp]): 
#			e_time = self._time(0.0001,a)
#			st_time = self._time(current_rel[i],a)
#			tim_shift = p_fail_time-st_time
#			print("eee",e_time,"  st",st_time)
#			tim = np.arange(st_time,e_time,1)
##			print("tim:",tim)
#			rel = self._reliability(tim,a)
#			plt.plot(tim,rel)
##			rel_res.append(rel)
##		sys.exit()
#		
#		a= copy.copy(alive_comp)
#		c= copy.copy(current_rel)
		alive_comp, current_rel,fail_time = self.fail_component(current_rel, alive_comp,alpha_max)
		
#		a, c,fail_time_ave = self.fail_component(c, a,alpha_ave[a])
		
#		print("alpha_max",alpha,"  alpha_ave:",alpha_ave)
		self.data[fail_time] = alpha_ave
		
		return alive_comp, current_rel,fail_time
		
#	def calc_time_until_failure(self, steady_temp, alive_comp, period, current_rel):
#		curr_period = self.totTime/period
#		curr_map = 0
#		no_of_intervals = len(steady_temp)
##		curr_spare_period =   period - (self.totTime % period)
#		curr_spare_period = (np.floor(curr_period)+1-curr_period)*period
#		
#		numb_alive = np.count_nonzero(alive_comp)
#		
#		t=np.zeros(len(alive_comp))
##		time = np.ones(len(alive_comp))*np.inf
#		cR = np.copy(current_rel[alive_comp])
#		
#		elapsedT = self._time(cR,steady_temp[curr_map][alive_comp])
#		testR = self._reliability(elapsedT + curr_spare_period, steady_temp[curr_map][alive_comp])
##		print("curr_spare_period",curr_spare_period,"  curr_spare_period1",curr_spare_period1)
#		randval = np.random.random_sample(numb_alive)
#		print("rand val:",randval)
#		randrel = randval * current_rel[alive_comp]
#		
#		j=-1
#		for i in range(len(alive_comp)):
#			if alive_comp[i] == True:
#				j+=1
#			else:
#				continue
#				
#			first_itter = True
#			while testR[j]>randrel[j]:
#				if first_itter == True:
#					t[i] = curr_spare_period
#					first_itter = False
#				else:
#					t[i]+=period
#				
##				print("t[{}]:".format(i),t[i]  )	
#				cR[j] = testR[j]
#				
#				curr_map = (curr_map+1)%no_of_intervals
#				
#				elapsedT[j] = self._time(cR[j],steady_temp[curr_map][alive_comp][j])
#				testR[j] = self._reliability(elapsedT[j] + period, steady_temp[curr_map][alive_comp][j])
#			
##				print("testR[j]:",testR[j]," > "," randrel[j]",randrel[j])
#				
#			if (cR[j]>randrel[j]):
#				lastElapsedT = self._time(randrel[j],steady_temp[curr_map][alive_comp][j])
#				eqT = self._time(cR[j],steady_temp[curr_map][alive_comp][j])
#				
#				t[i] += lastElapsedT-eqT
#				
#		
#		t[~np.array(alive_comp)] = np.inf
#			
#		minIdx = np.argmin(t)		

#		self.totTime +=t[minIdx]
#		
#		print("t:",t, " tot time:",self.totTime)
#		
#		
#		#TODO:check for min cores
#		alive_comp[minIdx] = False
#		
#		curr_period = (self.totTime-t[minIdx])/period
#		curr_map = int(np.floor(curr_period)%no_of_intervals)
#		curr_spare_period = (np.floor(curr_period)+1-curr_period)*period
#		
#		elapsedT = 0
#		tmpElapsedT = np.copy(curr_spare_period)
#		
#		eqElapsedT = self._time(current_rel[alive_comp],steady_temp[curr_map][alive_comp])
#		
#		tmpR = self._reliability(eqElapsedT+curr_spare_period,steady_temp[curr_map][alive_comp])
#		
#		while tmpElapsedT < t[minIdx]:
#			current_rel[alive_comp] = tmpR
#			elapsedT = np.copy(tmpElapsedT)
#			
#			tmpElapsedT += period
#			
#			curr_map = (curr_map+1)%no_of_intervals
#			
#			eqElapsedT = self._time(current_rel[alive_comp],steady_temp[curr_map][alive_comp])
#			
#			tmpR = self._reliability(eqElapsedT+period,steady_temp[curr_map][alive_comp])
#			
#		lastDelta = t[minIdx]-elapsedT
#		eqElapsedT = self._time(current_rel[alive_comp],steady_temp[curr_map][alive_comp])
#		
#		tmpR = self._reliability(eqElapsedT+lastDelta,steady_temp[curr_map][alive_comp])
#		print("time:",eqElapsedT+lastDelta)
#		print("alive:",alive_comp)
#		current_rel[alive_comp] = tmpR
#		
#		print("curr rel:",current_rel)
		
#		return alive_comp,
		
		
		
#	
#A = Ageing()
#temp = np.array([[45,10,12],[15,7,12],[12,63,12],[82,51,12],[49,32,12]])
#alive= [True,False,True]
#period = 0.5
#currR = np.array([1.0,1.0,1.0])
#print(currR)
#A.calc_time_until_failure(temp,alive,period,currR)

##rel = A._reliability(3.50353192, 15)
#time = A._time(rel,temp)


