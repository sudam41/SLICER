import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data0 = pd.read_csv('avetemp_1ghz.csv', sep=",")
data1 = pd.read_csv('avetemp_2ghz.csv', sep=",")
data2 = pd.read_csv('avetemp_3ghz.csv', sep=",")
data3 = pd.read_csv('avetemp_4ghz.csv', sep=",")

fail0=[]
fail1=[]
fail2=[]
fail3=[]
#fail1.append(0)
#fail2.append(0)
#fail3.append(0)
##for i in range(1,2):
##	ttf0 = np.array(data1.iloc[:,i])
##	ave = np.average(ttf0[0:4])
##	fail0.append(ave)

for i in range(1,4):
	ttf0 = np.array(data1.iloc[:,i])
	ave = np.average(ttf0[0:4])
	fail1.append(ave)


for i in range(1,4):
	ttf0 = np.array(data2.iloc[:,i])
	ave = np.average(ttf0[0:4])
	fail2.append(ave)

for i in range(1,4):
	ttf0 = np.array(data3.iloc[:,i])
	ave = np.average(ttf0[0:4])
	fail3.append(ave)


print(fail1)
SD = [3,5,6,7]
plt.rcParams.update({'font.size': 20})
err = SD/np.sqrt(9)
#print(MTTF)
#labels=["0","1\n(C3 Failed)","2\n(C4 Failed)","2\n(C2 Failed)","2\n(C6 Failed)","2\n(C5 Failed)"]#,10]
labels=["1GHz","2GHz","3GHz","4GHz"]#,10]
x = np.arange(len(labels))
width = 0.1 # the width of the bars

fig, ax = plt.subplots()
rects1 = ax.bar(x - width*2, fail0,
       width=width,
       yerr = err[0],
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Fail 0')
       
rects2 = ax.bar(x - width*1, fail1,
       width=width,
       yerr = err[1],
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Fail 1')
       
rects2 = ax.bar(x + width*0, fail2,
       width=width,
       yerr = err[2],
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Fail 2')
   
rects2 = ax.bar(x + width*1, fail3,
       width=width,
       yerr = err[3],
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Fail 3')

ax.set_ylabel('Temperature (C)')
ax.set_xticks(x,labels)
#ax.set_xticklabels(labels)
ax.set_xlabel('Frequency')
ax.set_title('Temperature vs frequency')
ax.yaxis.grid(True)
plt.rcParams.update({'font.size': 15})
ax.legend(loc=4)
plt.show()
#ttf0 = np.array(data2.iloc[:,1])
#ttf1 = np.array(data0.iloc[:,2])
#ttf2 = np.array(data0.iloc[:,3])
#ttf3 = np.array(data0.iloc[:,4])
#ttf4 = np.array(data0.iloc[:,5])
#ttf5 = np.array(data0.iloc[:,6])
#ttf6 = np.array(data0.iloc[:,7])
#ttf7 = np.array(data0.iloc[:,8])
#ttf8 = np.array(data0.iloc[:,9])



