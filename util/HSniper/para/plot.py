import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


data1 = pd.read_csv('PeriodicPower.log',sep='\t')
data2 = pd.read_csv('parallel/PeriodicPower.log',sep='\t')
#data2 = pd.read_csv('markers.stat',sep=',')

power_single = data1['Core0-TP']
power_core0 = data2['Core0-TP']
power_core1 = data2['Core1-TP']

plt.plot(power_single, label = "single")
plt.plot(power_core0, label = "core0")
plt.plot(power_core1, label = "core1")
plt.legend()
plt.show()
#time = np.arange(0,power.size*100,100)

#plt.plot(time,data1['Core0-TP'])
#maximum = max(power)

#liney = np.linspace(0,maximum,num=3)

#for task in data2.iterrows():
#	ts = task[1]['timestamp']
#	linex = np.array([ts,ts,ts])
#	plt.plot(linex,liney,label = task[1]['description'])	


#plt.xlabel("time(ns)")
#plt.ylabel("power(w)")
#plt.legend()
#plt.show()
