import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
# reading csv files
#data =  pd.read_csv('file.data', sep=",")
#print(data)
 
# reading tsv files
data = pd.read_csv('../MatEx/allTemp.data', sep="\t")
print(data['time'])

time = np.array(data['time'])
core1 = np.array(data['Core_1,1'])
core2 = np.array(data['Core_1,2'])
print("time size",time.size)

#fig, ax = plt.subplots(2,1)
numb =time.size
#ax[0].plot(time[0:numb],core1[0:numb])
#ax[1].plot(time[0:numb],core2[0:numb])
plt.plot(time[0:numb],core1[0:numb],'red')
plt.plot(time[0:numb],core2[0:numb],'blue')
plt.xlabel('Time')
plt.ylabel('Temp')
plt.show()
