import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


def _reliability( time, alpha):
		R = np.exp(-np.power(np.divide(time,alpha), 2))
#		print("temp:",self.model(temp)," rel:",R)
		return R
		
def _time(rel,alpha):
		T = alpha* np.power(-np.log(rel),(1/2))
#		print("time:",T)
		return T
		
df = pd.read_csv('data.csv', index_col=0)
print(df)
fail = df.columns[0]
time = np.arange(0,float(fail),1)

rel0 = _reliability(time,df[fail][0])
rel1 = _reliability(time,df[fail][1])

plt.plot(time,rel0, color='green')
plt.plot(time,rel1, color='red')


final_time = _time(0.00001,df[fail][1])

fail2 = df.columns[1]
time1 = np.arange(float(fail),final_time,1)

if np.isnan(df[fail2][0])==False:
	print("df[fail2][0]",df[fail2][0])
	sttime = _time(rel0[-1],df[fail2][0])
	gap = float(fail)-sttime
	rel00 = _reliability(time1,df[fail2][0])
	print("r:",rel00," t:",time1)
	plt.plot(time1+gap,rel00,color='blue')
elif np.isnan(df[fail2][1])==False:
	print("one")
	
	sttime = _time(rel1[-1],df[fail2][1])
	gap = float(fail)-sttime
	print("fail",type(fail)," gap",gap)
	rel11 = _reliability(time1+sttime,df[fail2][1])
	plt.plot(time1,rel11,color='blue')





plt.show()




