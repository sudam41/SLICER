#!/usr/bin/env python

import numpy as np
import pandas as pd
import sys


class WriteToFile():

	def powertrace(self,filename,power,time_intervals):
		file = open("../MatEx/{}".format(filename), "w")
		print(filename)
		file.write("time\tCore_1,1\tCore_1,2\n")

		file.write("-1\t0\t0\n")
		
		no_comp = power[0].size
		for i,t in enumerate(time_intervals):
			if t == time_intervals[-1]:
				power_val = power[i-1]
				file.write("{}".format(t))
				for p in power_val:
					file.write("\t{}".format(p[0]))
				file.write("\n{}\t{}\t{}".format(t+0.01,power_val[0][0]+0.01,power_val[1][0]+0.01))
			else:	
				power_val = power[i]
				file.write("{}".format(t))
				for p in power_val:
					file.write("\t{}".format(p[0]))
				file.write("\n")
				
	def powertrace_all(self,filename,power,time,names):

#		power[0] = np.insert(power[0],0,0)
#		power[1] = np.insert(power[1],0,0)
#		print("pow:",power[0][0:5],"  tim:",time[0:5])
#		print("Size:",time.size," ",power[0].size," ",power[1].size )
#		names = []

		data_ = {"time":time}
		for i,name in enumerate(names):
			print("name:",name,"\npower:",len(power[i]),"\ntime:",len(time))
			data_[name] = power[i]
		
#		sys.exit()
#		print("data:" ,data_)

#		data = {"time":time,"Core_1,1":power[0],"Core_1,2":power[1]}
		df = pd.DataFrame(data = data_)
#		print("dataframe")
		df.to_csv("../MatEx/{}".format(filename),index = False,sep='\t')
#		print("done!")
#		sys.exit()
		
		
		
