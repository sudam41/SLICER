import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import sys

data0 = pd.read_csv('fail0.csv', sep=",")
data1 = pd.read_csv('fail1.csv', sep=",")
data2 = pd.read_csv('fail2.csv', sep=",")
data3 = pd.read_csv('fail3.csv', sep=",")
data44 = pd.read_csv('fail4.csv', sep=",")
data55 = pd.read_csv('fail5.csv', sep=",")

data4 = pd.read_csv('shedule0.csv', sep=",")
data5 = pd.read_csv('shedule1.csv', sep=",")
data6 = pd.read_csv('shedule2.csv', sep=",")
data7 = pd.read_csv('shedule3.csv', sep=",")
data66 = pd.read_csv('shedule4.csv', sep=",")
data77 = pd.read_csv('shedule5.csv', sep=",")

fail0 = np.array(data0,dtype=float)
fail1 = np.array(data1,dtype=float)
fail2 = np.array(data2,dtype=float)
fail3 = np.array(data3,dtype=float)
fail4 = np.array(data44,dtype=float)
fail5 = np.array(data55,dtype=float)

shed0 = np.array(data4,dtype=float)
shed1 = np.array(data5,dtype=float)
shed2 = np.array(data6,dtype=float)
shed3 = np.array(data7,dtype=float)
shed4 = np.array(data66,dtype=float)
shed5 = np.array(data77,dtype=float)

fails = [fail0,fail1,fail2,fail3,fail4,fail5]
shed = [shed0,shed1,shed2,shed3,shed4,shed5]
plt.rcParams.update({'font.size': 10})
#time = np.arange(0,0.000101*15000,0.000101)
#time = np.linspace(0,0.0001615*8000,4951)
fig1, ax1 = plt.subplots(3,2)
for i,sh in enumerate(shed):
	print("--")
	for ass in sh:
#		print("assign:",ass[0])
		comp = ass[1]
		task = ass[2]
		start =  ass[3]
		end = ass[4]
		print("comp:",comp," task:",task," start:",start," end:",end)
		ax1[int(i/2),int(i%2)].broken_barh([(start,end-start)],(comp*1.5,1),facecolors ='tab:blue',)
		ax1[int(i/2),int(i%2)].set_title("Fail {}".format(i))
		ax1[int(i/2),int(i%2)].set_xlabel("Time(s)")
#		ax1[int(i/2),int(i%2)].set_yticks([0.5,2.0])
#		ax1[int(i/2),int(i%2)].set_yticklabels(['C0', 'C1','C2', 'C3','C4', 'C5'])

#plt.show()	
#	self.gnt.set_yticks([0.5,2.0])
#	self.gnt.set_yticklabels(['Component 0', 'Component 1'])
#	self.gnt.set_xticks(np.arange(0,0.3,0.05))



fig, ax = plt.subplots(3,2)
#plt.show()
for j,fail in enumerate(fails[4:]):
	time = fail[0]
	print("diff:",np.ediff1d(time[1:]))
	for i,core in enumerate(fail[1:7]):
		
		ax[int(i/2),int(i%2)].plot(time,core[:],label="F{}".format(j))
		ax[int(i/2),int(i%2)].set_ylim(ymin=45)
		ax[int(i/2),int(i%2)].set_title("Core {}".format(i))
		ax[int(i/2),int(i%2)].set_xlabel("Time(s)")
		ax[int(i/2),int(i%2)].set_ylabel("Temperature(C)")
	ax[int(i/2),int(i%2)].legend()
#plt.legend

#plt.show()


#plt.show()
avetemp = np.zeros((9,6))
sttemp =  np.zeros((9,6))
for j,fail in enumerate(fails[:]):
	time = fail[0]
	min_int = 0.0001
#	min_int = np.amin(np.ediff1d(time[1:]))
	print("st",time[0]," en:",time[1]," int:",min_int)
	time_uni = np.arange(time[0],time[-1],min_int)

#	coreave = np.zeros(9)
#	corest = np.zeros(9)
	for i,core in enumerate(fail[1:]):
#		print("i:",i)
		core_uni = np.interp(time_uni,time,core) 
		avetemp[i][j] = np.average(core_uni)
		sttemp[i][j] = np.std(core_uni)
#	avetemp.append(coreave)
#	sttemp.append(sttemp)

print("avetemp",avetemp)

fig, ax = plt.subplots()
labels=["0","1\n(C3 Failed)","2\n(C2 Failed)","3\n(C1 Failed)","4\n(C4 Failed)","5\n(C5 Failed)"]#,10]
x = np.arange(len(labels))
width = 0.1 
rects1 = ax.bar(x - width*5, avetemp[0],
       width=width,
       yerr = sttemp[0],
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Core 1')
       
rects2 = ax.bar(x - width*4, avetemp[1],
       width=width,
       yerr = sttemp[1],
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Core 2')
       
rects2 = ax.bar(x - width*3, avetemp[2],
       width=width,
       yerr = sttemp[2],
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Core 3')
   
rects2 = ax.bar(x - width*2, avetemp[3],
       width=width,
       yerr = sttemp[3],
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Core 4')
       
rects2 = ax.bar(x - width*1, avetemp[4],
       width=width,
       yerr = sttemp[4],
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Core 5')

rects2 = ax.bar(x - width*0, avetemp[5],
       width=width,
       yerr = sttemp[5],
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'Core 6')

rects2 = ax.bar(x + width*1, avetemp[6],
       width=width,
       yerr = sttemp[6],
       alpha=0.8,
       ecolor='black',
       color='grey',
       capsize=10,label= 'Core 7 - Disabled')
  
rects2 = ax.bar(x + width*2, avetemp[7],
       width=width,
       yerr = sttemp[7],
       alpha=0.8,
       ecolor='black',
       color='grey',
       capsize=10,label= 'Core 8 - Disabled')
       
rects2 = ax.bar(x + width*3, avetemp[8],
       width=width,
       yerr = sttemp[8],
       alpha=0.8,
       ecolor='black',
       color='grey',
       capsize=10,label= 'Core 9 - Disabled')


plt.show()
##ttf1 = np.array(data0.iloc[:,2])
##ttf2 = np.array(data0.iloc[:,3])
##ttf3 = np.array(data0.iloc[:,4])
##ttf4 = np.array(data0.iloc[:,5])
##ttf5 = np.array(data0.iloc[:,6])
##ttf6 = np.array(data0.iloc[:,7])
##ttf7 = np.array(data0.iloc[:,8])
##ttf8 = np.array(data0.iloc[:,9])


##print("temp:",data)
##sys.exit()
##data0 = pd.read_csv('idle0.csv', sep=",")
##data1 = pd.read_csv('idle1.csv', sep=",")
##data2 = pd.read_csv('idle2.csv', sep=",")
##data3 = pd.read_csv('idle3.csv', sep=",")
##data4 = pd.read_csv('idle4.csv', sep=",")
##data5 = pd.read_csv('idle5.csv', sep=",")
##data6 = pd.read_csv('idle6.csv', sep=",")
##data7 = pd.read_csv('idle7.csv', sep=",")
###data8 = pd.read_csv('idle8.csv', sep=",")


#err0 = np.array(data1.iloc[:,1])
#err1 = np.array(data1.iloc[:,2])
#err2 = np.array(data1.iloc[:,3])
#err3 = np.array(data1.iloc[:,4])
#err4 = np.array(data1.iloc[:,5])
#err5 = np.array(data1.iloc[:,6])
#err6 = np.array(data1.iloc[:,7])
#err7 = np.array(data1.iloc[:,8])
#err8 = np.array(data1.iloc[:,9])

###idle5=[0]
###ttf5=[0]

##M_idle = [np.average(idle0),np.average(idle1),np.average(idle2),np.average(idle3),np.average(idle4),np.average(idle5),np.average(idle6),np.average(idle7)]#,np.average(idle8)]
##SD_idle = [np.std(idle0),np.std(idle1),np.std(idle2),np.std(idle3),np.std(idle4),np.std(idle5),np.std(idle6),np.std(idle7)]#,np.std(idle8)]
##sderr_idle = SD_idle/np.sqrt(10)

##MTTF = [np.average(ttf0),np.average(ttf1),np.average(ttf2),np.average(ttf3),np.average(ttf4),np.average(ttf5),np.average(ttf6),np.average(ttf7)]#,np.average(ttf8)]

##SD = [np.std(ttf0),np.std(ttf1),np.std(ttf2),np.std(ttf3),np.std(ttf4),np.std(ttf5),np.std(ttf6),np.std(ttf7)]#,np.std(ttf8)]

#plt.rcParams.update({'font.size': 20})
##sderr = SD/np.sqrt(500)
##print(MTTF)
##labels=["0","1\n(C3 Failed)","2\n(C4 Failed)","2\n(C2 Failed)","2\n(C6 Failed)","2\n(C5 Failed)"]#,10]
#labels=["0","1\n(C3 Failed)","2\n(C2 Failed)","3\n(C1 Failed)","4\n(C4 Failed)","5\n(C5 Failed)"]#,10]
#x = np.arange(len(labels))
#width = 0.1 # the width of the bars

#fig, ax = plt.subplots()
#rects1 = ax.bar(x - width*5, ttf0,
#       width=width,
#       yerr = err0,
#       alpha=0.8,
#       ecolor='black',
#       capsize=10,label= 'Core 1')
#       
#rects2 = ax.bar(x - width*4, ttf1,
#       width=width,
#       yerr = err1,
#       alpha=0.8,
#       ecolor='black',
#       capsize=10,label= 'Core 2')
#       
#rects2 = ax.bar(x - width*3, ttf2,
#       width=width,
#       yerr = err2,
#       alpha=0.8,
#       ecolor='black',
#       capsize=10,label= 'Core 3')
#   
#rects2 = ax.bar(x - width*2, ttf3,
#       width=width,
#       yerr = err3,
#       alpha=0.8,
#       ecolor='black',
#       capsize=10,label= 'Core 4')
#       
#rects2 = ax.bar(x - width*1, ttf4,
#       width=width,
#       yerr = err4,
#       alpha=0.8,
#       ecolor='black',
#       capsize=10,label= 'Core 5')

#rects2 = ax.bar(x - width*0, ttf5,
#       width=width,
#       yerr = err5,
#       alpha=0.8,
#       ecolor='black',
#       capsize=10,label= 'Core 6')

#rects2 = ax.bar(x + width*1, ttf6,
#       width=width,
#       yerr = err6,
#       alpha=0.8,
#       ecolor='black',
#       color='grey',
#       capsize=10,label= 'Core 7 - Disabled')
#  
#rects2 = ax.bar(x + width*2, ttf7,
#       width=width,
#       yerr = err7,
#       alpha=0.8,
#       ecolor='black',
#       color='grey',
#       capsize=10,label= 'Core 8 - Disabled')
#       
#rects2 = ax.bar(x + width*3, ttf8,
#       width=width,
#       yerr = err8,
#       alpha=0.8,
#       ecolor='black',
#       color='grey',
#       capsize=10,label= 'Core 9 - Disabled')
#        
#       
#ax.set_ylabel('Temperature (C)')
#ax.set_xticks(x,labels)
##ax.set_xticklabels(labels)
#ax.set_xlabel('Number of Failures')
#ax.set_title('Temperature of Cores')
#ax.yaxis.grid(True)
#plt.rcParams.update({'font.size': 15})
#ax.legend(loc=4)




##plt.plot(MTTF)
#plt.show()



##data0 = pd.read_csv('et0.csv', sep=",")
##data1 = pd.read_csv('et1.csv', sep=",")
##data2 = pd.read_csv('et2.csv', sep=",")
##data3 = pd.read_csv('et3.csv', sep=",")
##data4 = pd.read_csv('et4.csv', sep=",")
##data5 = pd.read_csv('et5.csv', sep=",")
##data6 = pd.read_csv('et6.csv', sep=",")
##data7 = pd.read_csv('et7.csv', sep=",")
##data8 = pd.read_csv('et8.csv', sep=",")


##ttf0 = np.array(data0.iloc[:,1])
##ttf1 = np.array(data1.iloc[:,1])
##ttf2 = np.array(data2.iloc[:,1])
##ttf3 = np.array(data3.iloc[:,1])
##ttf4 = np.array(data4.iloc[:,1])
##ttf5 = np.array(data5.iloc[:,1])
##ttf6 = np.array(data6.iloc[:,1])
##ttf7 = np.array(data7.iloc[:,1])
##ttf8 = np.array(data8.iloc[:,1])


##MTTF = [np.average(ttf0),np.average(ttf1),np.average(ttf2),np.average(ttf3),np.average(ttf4),np.average(ttf5),np.average(ttf6),np.average(ttf7),np.average(ttf8)]

##SD = [np.std(ttf0),np.std(ttf1),np.std(ttf2),np.std(ttf3),np.std(ttf4),np.std(ttf5),np.std(ttf6),np.std(ttf7),np.std(ttf8)]
##sderr = SD/np.sqrt(50)
##print(MTTF)
##x_pos=[2,3,4,5,6,7,8,9,10]

##plt.rcParams.update({'font.size': 20})
##fig, ax = plt.subplots()
##ax.bar(x_pos, MTTF,
##       yerr=sderr,
##       align='center',
##       alpha=0.5,
##       ecolor='black',
##       capsize=10)
##ax.set_ylabel('Mean Execution Time (Seconds)')
##ax.set_xticks(x_pos)
##ax.set_xlabel('Number of Cores')
###ax.set_xticklabels(labels)
##ax.set_title('Mean Execution Time of Simulation')
##ax.yaxis.grid(True)


###plt.plot(MTTF)
##plt.show()
