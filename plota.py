import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


#data0 = pd.read_csv('ttf0.csv', sep=",")
#data1 = pd.read_csv('ttf1.csv', sep=",")
#data2 = pd.read_csv('ttf2.csv', sep=",")
#data3 = pd.read_csv('ttf3.csv', sep=",")
#data4 = pd.read_csv('ttf4.csv', sep=",")
#data5 = pd.read_csv('ttf5.csv', sep=",")
#data6 = pd.read_csv('ttf6.csv', sep=",")
#data7 = pd.read_csv('ttf7.csv', sep=",")
#data8 = pd.read_csv('ttf8.csv', sep=",")


#ttf0 = np.array(data0.iloc[:,1])
#ttf1 = np.array(data1.iloc[:,1])
#ttf2 = np.array(data2.iloc[:,1])
#ttf3 = np.array(data3.iloc[:,1])
#ttf4 = np.array(data4.iloc[:,1])
#ttf5 = np.array(data5.iloc[:,1])
#ttf6 = np.array(data6.iloc[:,1])
#ttf7 = np.array(data7.iloc[:,1])
#ttf8 = np.array(data8.iloc[:,1])

she = np.array([0.00018164100765716285,0.00018878300033975393,0.00020289700478315353,0.00020798300101887435,0.00021380299585871398,0.0002338980120839551,0.00024630100233480334,0.00024610699620097876,0.00025175599148496985])
power = np.array([0.3252984910068335,0.30586831500113476,0.3168931959953625,0.3298218269919744,0.32142339400888886,0.33592669501376804,0.3517217030021129,0.37396496400469914,0.5266293379972922])
thermal =np.array([0.5803077269956702,0.5903865529980976,0.6947993939975277,0.8595640799903776,1.069623887000489,1.3740170220116852,1.5312144519994035,1.9757908470055554,1.8665753669920377])
ageing=np.array([0.04691785199975129,0.034751304003293626,0.04342164300032891,0.05375838000327349,0.048519882999244146,0.0547739809990162,0.059437428004457615,0.06768173800082877,0.07824933600204531])



#MTTF = [np.average(ttf0),np.average(ttf1),np.average(ttf2),np.average(ttf3),np.average(ttf4),np.average(ttf5),np.average(ttf6),np.average(ttf7),np.average(ttf8)]

#SD = [np.std(ttf0),np.std(ttf1),np.std(ttf2),np.std(ttf3),np.std(ttf4),np.std(ttf5),np.std(ttf6),np.std(ttf7),np.std(ttf8)]
#plt.rcParams.update({'font.size': 20})
#sderr = SD/np.sqrt(50)
#print(MTTF)
x_pos=[2,3,4,5,6,7,8,9,10]
fig, ax = plt.subplots()
ax.bar(x_pos, thermal,
       align='center',
       ecolor='black',
       capsize=10,label= 'Matex')
       
ax.bar(x_pos, power,
       align='center',
       ecolor='black',
       capsize=10,label= 'Constructing Powertrace files')

#ax.bar(x_pos, she,
#       align='center',
#       ecolor='black',
#       capsize=10,label= 'Scheduling')

ax.bar(x_pos, ageing,
       align='center',
       ecolor='black',
       capsize=10,label= 'Ageing')       
       

ax.set_ylabel('Time(Seconds)')
ax.set_xticks(x_pos)
#ax.set_xticklabels(labels)
ax.set_xlabel('Number of Cores')
ax.set_title('Execution Time Breakdown')
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
