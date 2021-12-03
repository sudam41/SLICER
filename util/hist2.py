import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.stats as st
import sys
df = pd.read_csv('../results/ttf.csv', sep=',',index_col=0)

TTF0 = df['ttf0']
TTF1 = df['ttf1']
TTF2 = df['ttf2']
FFT = df['fft1']
#stats = st.exponweib.fit(TTF, 0, 0, scale=1, loc=0)
#print("stats:",st.exponweib.pdf(TTF, *stats))
#plt.plot(st.exponweib.pdf(TTF, *stats))
#plt.show()
plt.rcParams.update({'font.size': 20})
plt.hist(TTF0,cumulative=-1,density=True,stacked=True, bins=100,label = '0.0005s')
plt.hist(TTF1,cumulative=-1,density=True,stacked=True, bins=100,label = '0.0105s')
plt.hist(TTF2,cumulative=-1,density=True,stacked=True, bins=100,label = '0.0205s')


mn, mx = plt.ylim()
y_ave_hist = np.linspace(mn, mx, 3)
x_ave_ttf0 = np.ones(3)*np.average(TTF0)
x_ave_ttf1 = np.ones(3)*np.average(TTF1)
x_ave_ttf2 = np.ones(3)*np.average(TTF2)

plt.plot(x_ave_ttf0,y_ave_hist,label='MTTF 0.0005s')
plt.plot(x_ave_ttf1,y_ave_hist,label='MTTF 0.0105s')
plt.plot(x_ave_ttf2,y_ave_hist,label='MTTF 0.0205s')
plt.legend()
plt.ylabel("Probability")
plt.xlabel("TTF (Hours)")
plt.title("System Failure Cumulative Distribution Function");
plt.show()


plt.rcParams.update({'font.size': 20})
fig, axs = plt.subplots(2,2)
fig.suptitle('Time to Failure')

#axs[0].plot(TTF, st.exponweib.pdf(TTF, *stats))
axs[0][0].hist(TTF,density=False, bins=50)
axs[1][0].hist(FFT,density=False, bins=50)

#print(bins)
#plt.sca(axs[0])
#mn, mx = plt.xlim()
#axs[0].set_xlim(mn, mx)
#kde_xs = np.linspace(mn, mx, 300)
#kde = st.exponweib.pdf(TTF)
#axs[0].plot(kde_xs, kde.pdf(kde_xs), label="PDF")
#plt.legend(loc="upper left")
axs[0][0].set_ylabel("Frequency")
axs[0][0].set_xlabel("TTF (Hours)")
axs[0][0].set_title("System Failure Histogram");
axs[1][0].set_ylabel("Frequency")
axs[1][0].set_xlabel("TTF (Hours)")
axs[1][0].set_title("First Failure Histogram");

axs[0][1].hist(TTF,cumulative=-1,density=True,stacked=True, bins=100)
axs[0][1].set_ylabel("Probability")
axs[0][1].set_xlabel("TTF (Hours)")
axs[0][1].set_title("System Failure Cumulative Distribution Function");

axs[1][1].hist(FFT,cumulative=-1,density=True,stacked=True, bins=100)
axs[1][1].set_ylabel("Probability")
axs[1][1].set_xlabel("TTF (Hours)")
axs[1][1].set_title("First Failure Cumulative Distribution Function");


#####
#dfm = pd.read_csv('ttf.csv', sep=',',index_col=0)

#TTFm = dfm['ttf']
#FFTm = dfm['fft']
#stats = st.exponweib.fit(TTFm, 0, 0, scale=1, loc=0)
#print("stats:",st.exponweib.pdf(TTFm, *stats))
##plt.plot(st.exponweib.pdf(TTF, *stats))
##plt.show()


##axs[0].plot(TTF, st.exponweib.pdf(TTF, *stats))
#axs[0][0].hist(TTFm,density=False, bins=50)
#axs[1][0].hist(FFTm,density=False, bins=50)

##print(bins)
##plt.sca(axs[0])
##mn, mx = plt.xlim()
##axs[0].set_xlim(mn, mx)
##kde_xs = np.linspace(mn, mx, 300)
##kde = st.exponweib.pdf(TTF)
##axs[0].plot(kde_xs, kde.pdf(kde_xs), label="PDF")
##plt.legend(loc="upper left")

#axs[0][1].hist(TTFm,cumulative=-1,density=True,stacked=True, bins=100)


#axs[1][1].hist(FFTm,cumulative=-1,density=True,stacked=True, bins=100)


plt.sca(axs[0][0])
mn, mx = plt.ylim()
y_ave_hist = np.linspace(mn, mx, 3)
x_ave_ttf = np.ones(3)*np.average(TTF)


plt.sca(axs[1][1])
mn, mx = plt.ylim()
y_ave_cdf = np.linspace(mn, mx, 3)
x_ave_fft = np.ones(3)*np.average(FFT)

axs[0][0].plot(x_ave_ttf,y_ave_hist,'r')
axs[0][1].plot(x_ave_ttf,y_ave_cdf,'r')
axs[1][0].plot(x_ave_fft,y_ave_hist,'r')
axs[1][1].plot(x_ave_fft,y_ave_cdf,'r')


plt.show()
#aaa = np.cumsum(-bins)
#plt.plot(aaa)
#plt.show()

#cy = np.cumsum(TTF)
#plt.plot(cy)
#plt.show()
