import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data0 = pd.read_csv('shedule_heft_2core0.csv', sep=",")

dat = np.array(data0)

print(dat)
plt.rcParams.update({'font.size': 14})

for task in dat:
	plt.broken_barh([(task[4],task[5]-task[4])],(task[2]*1.5,1),facecolors ='tab:blue',edgecolor="black",label = "Task {}".format(task[1]))
	plt.text(((task[5]+task[4])/2)-0.03,(task[2]*1.5)+0.5,"Task {}".format(int(task[1])))

#plt.yticks([0.5,2.0])
#plt.ylabels(['Component 0', 'Component 1'])
plt.yticks([0.5, 2.0, 3.5], ['Core 0', 'Core 1', 'Core 2']) 
plt.xticks(np.arange(0,1.8,0.1))
plt.ylim(0,4.0)
plt.xlabel("Time(s)")
plt.title("Schedule")
#plt.set_axisbelow(True)
#plt.grid()
plt.show()
