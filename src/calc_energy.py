import numpy as np
import pandas as pd
import sys
from parse_power_trace import parse_power


def calc_ave_energy_task(task,component,frequency):
	power_t = np.array(parse_power(task,component,frequency))

	interval = 0.001

	energy_t = power_t*interval
	
	ave_energy = np.mean(energy_t)

	return ave_energy
	
	
def calc_tot_power(task,component,frequency):
	power_t = np.array(parse_power(task,component,frequency))
	
	interval = 0.001
	
	tot_power = np.sum(power_t)
#	print("p:",tot_power,"len:",len(power_t))
	return tot_power, len(power_t)
#	print("energy trace = ",energy_t,"\npower trace = ",power_t,"\nAverage Energy = ",np.mean(energy_t),"\n Average Power = ",np.mean(power_t))


#time = interval * len(power_t)
#print("time:",time,"  power len:",len(power_t))
#print("EE:",np.mean(power_t)*time)

