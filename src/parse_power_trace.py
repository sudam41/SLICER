import numpy as np
import pandas as pd


def parse_power(task,comp,freq):
	#TODO:Parse all tasks first and maintain them in the application object,c
#	print("T:",task," C:",comp," freq:",freq)
	data = pd.read_csv("../powertraces/C{}/Task{}f{}.ptrace".format(comp,task,freq),sep='\t')
	
#	power = np.array(data['Core_1,{}'.format(comp+1)])
	power = np.array(data['Core_1,1'])
	return power
	
	

