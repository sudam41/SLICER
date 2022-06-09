import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os
import sys
# reading csv files
#data =  pd.read_csv('file.data', sep=",")
#print(data)
 
# reading tsv files

def import_matex_data(names,mc_instance):
	data = pd.read_csv('../MatEx/results/allTemp_{}.data'.format(mc_instance), sep="\t")
#	print(data['time'])

	time = np.array(data['time'])
	temp = []
	temp.append(time)
	for i in names:
#		for j in range(num_cores[1]):
#			col = "Core_{},{}".format(i+1,j+1)
#			print(col)
		temp.append(np.array(data[i]))
#	print(temp)	
#	sys.exit()
	os.remove('../MatEx/results/allTemp_{}.data'.format(mc_instance))
	return temp
	
	
	

	
	
#		core1 = np.array(data['Core_1,1'])
#		core2 = np.array(data['Core_1,2'])
#		print("time size",time.size)

#	fig, ax = plt.subplots(2,1)
#	numb =time.size
#	ax[0].plot(time[0:numb],core1[0:numb])
#	ax[1].plot(time[0:numb],core2[0:numb])
#	plt.show()


