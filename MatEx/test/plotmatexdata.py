import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
# reading csv files
#data =  pd.read_csv('file.data', sep=",")
#print(data)
 
# reading tsv files
data1 = pd.read_csv('allTemp1.data', sep="\t")
data2 = pd.read_csv('allTemp_5.data', sep="\t")
#print(data['time'])

time = np.array(data1['time'])
core1 = np.array(data1['Core_1,1'])
core2 = np.array(data1['Core_1,2'])
core3 = np.array(data1['Core_1,3'])
core4 = np.array(data1['Core_1,4'])
#print("time size",time1.size)

fig, ax = plt.subplots(4,1)
numb =time.size
ax[0].plot(time[0:numb],core1[0:numb])
ax[1].plot(time[0:numb],core2[0:numb])
ax[2].plot(time[0:numb],core3[0:numb])
ax[3].plot(time[0:numb],core4[0:numb])


time2 = np.array(data2['time'])
core1_2 = np.array(data2['Core_1,1'])
core2_2 = np.array(data2['Core_1,2'])
core3_2 = np.array(data2['Core_1,3'])
core4_2 = np.array(data2['Core_1,4'])
#print("time size",time.size)

#fig, ax = plt.subplots(4,1)
numb =time2.size
ax[0].plot(time2[0:numb],core1_2[0:numb],'--')
ax[1].plot(time2[0:numb],core2_2[0:numb],'--')
ax[2].plot(time2[0:numb],core3_2[0:numb],'--')
ax[3].plot(time2[0:numb],core4_2[0:numb],'--')



plt.show()
