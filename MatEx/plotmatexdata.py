import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
# reading csv files
#data =  pd.read_csv('file.data', sep=",")
#print(data)
 
# reading tsv files
data = pd.read_csv('allTemp.data', sep="\t")
#print(data['time'])

time = np.array(data['time'])
core1 = np.array(data['Core_1,1'])
core2 = np.array(data['Core_1,2'])
core3 = np.array(data['Core_1,3'])
core4 = np.array(data['Core_1,4'])
print("time size",time.size)
plt.rcParams.update({'font.size': 14})
fig, ax = plt.subplots(4,1)
numb =time.size

ax[0].plot(time[0:numb],core1[0:numb])
ax[1].plot(time[0:numb],core2[0:numb])
ax[2].plot(time[0:numb],core3[0:numb]+10)
ax[3].plot(time[0:numb],core4[0:numb])

ax[0].set_ylabel('Temperature (C)')
#ax.set_xticklabels(labels)
ax[0].set_xlabel('Time(s)')
#ax[0].set_title('Core 1')


ax[1].set_ylabel('Temperature (C)')
#ax.set_xticklabels(labels)
ax[1].set_xlabel('Time(s)')
#ax[1].set_title('Core 2')


ax[2].set_ylabel('Temperature (C)')
#ax.set_xticklabels(labels)
ax[2].set_xlabel('Time(s)')
#ax[2].set_title('Core 3')

ax[3].set_ylabel('Temperature (C)')
#ax.set_xticklabels(labels)
ax[3].set_xlabel('Time(s)')
#ax[3].set_title('Core 4')
plt.show()
