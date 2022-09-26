import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data0 = pd.read_csv('temp_heft_2core1.csv', sep=",")

dat = np.array(data0)

print(len(dat))

time = dat[0]

fig, axs = plt.subplots(3,3,sharex='col', sharey='row',
                        gridspec_kw={'hspace': 0, 'wspace': 0})
fig.suptitle('Temperature of Cores')


for i,core in enumerate(dat[1:]):
	if i<2:
		axs[int((8-i)/3),int(i%3)].plot(time,core)
		axs[int((8-i)/3),int(i%3)].vlines(1.8,120,min(core),linestyles ="dotted", colors ="red",label="Deadline")
		axs[int((8-i)/3),int(i%3)].vlines(3.6,120,min(core),linestyles ="dotted", colors ="red")
		axs[int((8-i)/3),int(i%3)].vlines(5.4,120,min(core),linestyles ="dotted", colors ="red")
	else:
		axs[int((8-i)/3),int(i%3)].plot(time,core,color="grey")
	
	
#	axs[int(i/3),int(i%3)].vlines(6.8,120,min(core),linestyles ="dotted", colors ="red")
	plt.rcParams.update({'font.size': 14})
	axs[int((8-i)/3),int(i%3)].set_title("Core {}".format(i), y=0.15, pad=-14)
	axs[int((8-i)/3),int(i%3)].set_ylim([20,130])
#	axs[int((8-i)/3),int(i%3)].grid()

# set labels
plt.setp(axs[-1, :], xlabel='Time(s)')
plt.setp(axs[:, 0], ylabel='Temperature(C)')
plt.legend(bbox_to_anchor=(1.00, 1.0), loc='upper left')
#plt.xlabel("Time(s)")
#plt.ylabel("Temperature(C)")
plt.show()
