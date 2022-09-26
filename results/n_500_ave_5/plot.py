import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


data0 = pd.read_csv('ttf0.csv', sep=",")
data1 = pd.read_csv('ttf1.csv', sep=",")
data2 = pd.read_csv('ttf2.csv', sep=",")
data3 = pd.read_csv('ttf3.csv', sep=",")
data4 = pd.read_csv('ttf4.csv', sep=",")
#data5 = pd.read_csv('ttf5.csv', sep=",")
#data6 = pd.read_csv('ttf6.csv', sep=",")
#data7 = pd.read_csv('ttf7.csv', sep=",")
#data8 = pd.read_csv('ttf8.csv', sep=",")


ttf0 = np.array(data0.iloc[:,1])
ttf1 = np.array(data1.iloc[:,1])
ttf2 = np.array(data2.iloc[:,1])
ttf3 = np.array(data3.iloc[:,1])
ttf4 = np.array(data4.iloc[:,1])
#ttf5 = np.array(data5.iloc[:,1])
#ttf6 = np.array(data6.iloc[:,1])
#ttf7 = np.array(data7.iloc[:,1])
#ttf8 = np.array(data8.iloc[:,1])




data0 = pd.read_csv('idle0.csv', sep=",")
data1 = pd.read_csv('idle1.csv', sep=",")
data2 = pd.read_csv('idle2.csv', sep=",")
data3 = pd.read_csv('idle3.csv', sep=",")
data4 = pd.read_csv('idle4.csv', sep=",")
#data5 = pd.read_csv('idle5.csv', sep=",")
#data6 = pd.read_csv('idle6.csv', sep=",")
#data7 = pd.read_csv('idle7.csv', sep=",")
#data8 = pd.read_csv('idle8.csv', sep=",")


idle0 = np.array(data0.iloc[:,1])
idle1 = np.array(data1.iloc[:,1])
idle2 = np.array(data2.iloc[:,1])
idle3 = np.array(data3.iloc[:,1])
idle4 = np.array(data4.iloc[:,1])
#idle5 = np.array(data5.iloc[:,1])
#idle6 = np.array(data6.iloc[:,1])
#idle7 = np.array(data7.iloc[:,1])
#idle8 = np.array(data8.iloc[:,1])

idle5=[0]
ttf5=[0]

M_idle = [np.average(idle0),np.average(idle1),np.average(idle2),np.average(idle3),np.average(idle4),np.average(idle5)]#,np.average(idle6),np.average(idle7),np.average(idle8)]
SD_idle = [np.std(idle0),np.std(idle1),np.std(idle2),np.std(idle3),np.std(idle4),np.std(idle5)]#,np.std(idle6),np.std(idle7),np.std(idle8)]
sderr_idle = SD_idle/np.sqrt(10)

MTTF = [np.average(ttf0),np.average(ttf1),np.average(ttf2),np.average(ttf3),np.average(ttf4),np.average(ttf5)]#,np.average(ttf6),np.average(ttf7),np.average(ttf8)]

SD = [np.std(ttf0),np.std(ttf1),np.std(ttf2),np.std(ttf3),np.std(ttf4),np.std(ttf5)]#,np.std(ttf6),np.std(ttf7),np.std(ttf8)]
plt.rcParams.update({'font.size': 20})
sderr = SD/np.sqrt(10)
print(MTTF)
labels=[2,3,4,5,6,7]#,8,9,10]
x = np.arange(len(labels))
width = 0.4  # the width of the bars

fig, ax = plt.subplots()
rects1 = ax.bar(x - width/2, MTTF,
       yerr=sderr,
       width=width,
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'MTTF')
       
rects2 = ax.bar(x + width/2, M_idle,
       yerr=sderr_idle,
       width=width,
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Mean Idle Time per Alive Core')
       
ax.set_ylabel('Time (Hours)')
ax.set_xticks(x,labels)
#ax.set_xticklabels(labels)
ax.set_xlabel('Number of Cores')
ax.set_title('Mean Time to Failure of the System')
ax.yaxis.grid(True)

ax.legend()




#plt.plot(MTTF)
plt.show()



#data0 = pd.read_csv('et0.csv', sep=",")
#data1 = pd.read_csv('et1.csv', sep=",")
#data2 = pd.read_csv('et2.csv', sep=",")
#data3 = pd.read_csv('et3.csv', sep=",")
#data4 = pd.read_csv('et4.csv', sep=",")
#data5 = pd.read_csv('et5.csv', sep=",")
#data6 = pd.read_csv('et6.csv', sep=",")
#data7 = pd.read_csv('et7.csv', sep=",")
#data8 = pd.read_csv('et8.csv', sep=",")


#ttf0 = np.array(data0.iloc[:,1])
#ttf1 = np.array(data1.iloc[:,1])
#ttf2 = np.array(data2.iloc[:,1])
#ttf3 = np.array(data3.iloc[:,1])
#ttf4 = np.array(data4.iloc[:,1])
#ttf5 = np.array(data5.iloc[:,1])
#ttf6 = np.array(data6.iloc[:,1])
#ttf7 = np.array(data7.iloc[:,1])
#ttf8 = np.array(data8.iloc[:,1])


#MTTF = [np.average(ttf0),np.average(ttf1),np.average(ttf2),np.average(ttf3),np.average(ttf4),np.average(ttf5),np.average(ttf6),np.average(ttf7),np.average(ttf8)]

#SD = [np.std(ttf0),np.std(ttf1),np.std(ttf2),np.std(ttf3),np.std(ttf4),np.std(ttf5),np.std(ttf6),np.std(ttf7),np.std(ttf8)]
#sderr = SD/np.sqrt(50)
#print(MTTF)
#x_pos=[2,3,4,5,6,7,8,9,10]

#plt.rcParams.update({'font.size': 20})
#fig, ax = plt.subplots()
#ax.bar(x_pos, MTTF,
#       yerr=sderr,
#       align='center',
#       alpha=0.5,
#       ecolor='black',
#       capsize=10)
#ax.set_ylabel('Mean Execution Time (Seconds)')
#ax.set_xticks(x_pos)
#ax.set_xlabel('Number of Cores')
##ax.set_xticklabels(labels)
#ax.set_title('Mean Execution Time of Simulation')
#ax.yaxis.grid(True)


##plt.plot(MTTF)
#plt.show()
