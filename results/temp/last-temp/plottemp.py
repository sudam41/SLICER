import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data0 = pd.read_csv('allftemp.csv', sep=",")

temp = np.array(data0.iloc[:,1])


data1 = pd.read_csv('temp.csv', sep=",")

temp1 = np.array(data1.iloc[:,1])

print(temp)


labels=[2,3,4,5,6,7,8,9]
plt.rcParams.update({'font.size': 20})
x = np.arange(len(labels))
width = 0.4  # the width of the bars

fig, ax = plt.subplots()
rects1 = ax.bar(x+width/2, temp,
       width=width,
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'All Failures')
       
       
rects2 = ax.bar(x- width/2, temp1,
       width=width,
       alpha=0.8,
       ecolor='black',
       capsize=10,label= 'First Failure')
       
       
ax.set_ylabel('Temperature (C)')
ax.set_xticks(x,labels)
#ax.set_xticklabels(labels)
ax.set_xlabel('Number of Cores')
ax.set_title('Average Temperature')
ax.yaxis.grid(True)

plt.show()
