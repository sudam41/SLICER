#!/usr/bin/env python

import numpy as np


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
			else:	
				power_val = power[i]
				file.write("{}".format(t))
				for p in power_val:
					file.write("\t{}".format(p[0]))
				file.write("\n")
