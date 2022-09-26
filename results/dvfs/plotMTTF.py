import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math

heft2 = pd.read_csv('./HEFT/TTF2.csv', sep=",")
heft3 = pd.read_csv('./HEFT/TTF3.csv', sep=",")
heft4 = pd.read_csv('./HEFT/TTF4.csv', sep=",")

dnds2 = pd.read_csv('./DNDS/TTF2.csv', sep=",")
dnds3 = pd.read_csv('./DNDS/TTF3.csv', sep=",")
dnds4 = pd.read_csv('./DNDS/TTF4.csv', sep=",")

dwds2 = pd.read_csv('./DWDS/TTF2.csv', sep=",")
dwds3 = pd.read_csv('./DWDS/TTF3.csv', sep=",")
dwds4 = pd.read_csv('./DWDS/TTF4.csv', sep=",")

H2 = np.array(heft2.iloc[:,1])
H3 = np.array(heft3.iloc[:,1])
H4 = np.array(heft4.iloc[:,1])

DN2 = np.array(dnds2.iloc[:,1])
DN3 = np.array(dnds3.iloc[:,1])
DN4 = np.array(dnds4.iloc[:,1])

DW2 = np.array(dwds2.iloc[:,1])
DW3 = np.array(dwds3.iloc[:,1])
DW4 = np.array(dwds4.iloc[:,1])


#plt.hist(dat0,bins = 100)
#plt.hist(dat1,bins = 100)
#plt.show()
HEFT_mean = np.array([np.average(H2),np.average(H3),np.average(H4)])
DNDS_mean = np.array([np.average(DN2),np.average(DN3),np.average(DN4)])
DWDS_mean = np.array([np.average(DW2),np.average(DW3),np.average(DW4)])

HEFT_std = np.array([np.std(H2)/math.sqrt(len(H2)),np.std(H3)/math.sqrt(len(H3)),np.std(H4)/math.sqrt(len(H4))])
DNDS_std = np.array([np.std(DN2)/math.sqrt(len(DN2)),np.std(DN3)/math.sqrt(len(DN3)),np.std(DN4)/math.sqrt(len(DN4))])
DWDS_std = np.array([np.std(DW2)/math.sqrt(len(DW2)),np.std(DW3)/math.sqrt(len(DW3)),np.std(DW4)/math.sqrt(len(DW4))])

#print("MTTF: HEFT", np.average(H2)/math.sqrt(len(H2))," DWDS:",np.average(H3)/math.sqrt(len(H3))," DNDS",np.average(H4)/math.sqrt(len(H4)))
#print("MTTF: HEFT", np.average(DN2)/math.sqrt(len(DN2))," DWDS:",np.average(DN3)/math.sqrt(len(DN3))," DNDS",np.average(DN4)/math.sqrt(len(DN4))
#print("MTTF: HEFT", np.average(DW2)/math.sqrt(len(DW2))," DWDS:",np.average(DW3)/math.sqrt(len(DW3))," DNDS",np.average(DW4)/math.sqrt(len(DW4))
plt.rcParams.update({'font.size': 20})
labels = ["2 Cores","3 Cores","4 Cores"]

x = np.arange(len(labels))
width = 0.1 # the width of the bars

fig, ax = plt.subplots()

rects1 = ax.bar(x - width*1, HEFT_mean,
       width=width,
       yerr = HEFT_std,
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'HEFT')
       
rects2 = ax.bar(x - width*0, DNDS_mean,
       width=width,
       yerr = DNDS_std,
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'DNDS')
       
rects2 = ax.bar(x + width*1, DWDS_mean,
       width=width,
       yerr = DWDS_std,
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'DWDS')

ax.set_ylabel('MTTF (Hours)')
ax.set_xticks(x,labels)
#ax.set_xticklabels(labels)
#ax.set_xlabel('Frequency')
#ax.set_title('Temperature vs frequency')
ax.yaxis.grid(True)
plt.rcParams.update({'font.size': 15})
ax.legend(loc=2)
plt.show()
