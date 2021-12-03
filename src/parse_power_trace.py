import numpy as np
import pandas as pd


def parse_power(task,comp):
	data = pd.read_csv('../powertraces/Task{}.ptrace'.format(task),sep='\t')
	
	power = np.array(data['Core_1,{}'.format(comp+1)])
	
	return power
	
	

