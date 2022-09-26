import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.stats as stats
import sys

from reliability.Fitters import Fit_Weibull_3P
from reliability.Distributions import Weibull_Distribution
from reliability.Probability_plotting import plot_points
from reliability.Other_functions import make_right_censored_data, histogram

df10 = pd.read_csv('ttf.csv', sep=',',index_col=0)
#df3 = pd.read_csv('3/ttf.csv', sep=',',index_col=0)
#df2 = pd.read_csv('2/ttf.csv', sep=',',index_col=0)

TTF0 = np.array(df10['TTF0'])

TTF1 = np.array(df10['TTF1'])
TTF2 = np.array(df10['TTF2'])

TTF3 = np.array(df10['TTF3'])

TTF4 = np.array(df10['TTF4'])
TTF5 = np.array(df10['TTF5'])
TTF6 = np.array(df10['TTF6'])
TTF7 = np.array(df10['TTF7'])
TTF8 = np.array(df10['TTF8'])
TTF9 = np.array(df10['TTF9'])
TTF10 = np.array(df10['TTF10'])
TTF11 = np.array(df10['TTF11'])
TTF12 = np.array(df10['TTF12'])

TTF = [TTF0,TTF1,TTF2,TTF3,TTF4,TTF5,TTF6,TTF7,TTF8,TTF9,TTF10,TTF11,TTF12]
Inter = [0.0005,0.0020,0.0038,0.0055, 0.0105, 0.0205,0.0305,0.0405,0.0505,0.0605,0.0705,0.0805,0.0905]
y_ave_cdf = np.linspace(0, 1, 3)
color=['red','green','blue','orange','grey','navy','black','darkgreen','violet','coral','teal','maroon']
for i in range(0,12):
	
	wbf = Fit_Weibull_3P(failures=TTF[i],  show_probability_plot=False, print_results=False)
	wbf.distribution.SF(label="Interval={}".format(Inter[i]),plot_CI=False,color=color[i])

	x_ave_ttf = np.ones(3)*np.average(TTF[i])
	plt.plot(x_ave_ttf,y_ave_cdf,label="MTTF({})".format(Inter[i]),color=color[i],linestyle='dashed')
	
plt.legend()
plt.title('Cumulative Distribution Function of System Failure')
plt.ylabel('Probability')
plt.xlabel('TTF(Hours)')
plt.show()
#FFT = df['fft']
#stats = st.exponweib.fit(TTF, 0, 0, scale=1, loc=0)
#print("stats:",st.exponweib.pdf(TTF, *stats))

#plt.hist(TTF,density=False, bins=50)
#c, loc, scale = st.weibull_min.fit(TTF)
#x = st.weibull_min.rvs(c, loc, scale, size=1000)
print("TTF:",np.array(TTF))
#fig, axs = plt.subplots(2)
#fit = Fit_Weibull_3P(failures=np.array(TTF))
#plt.yscale('linear')
#plt.xscale('linear')

fig, axs = plt.subplots(2,2)
plt.title("Time to Failure (Interval = 0.0205)")
plt.sca(axs[0][0])
wbf = Fit_Weibull_3P(failures=TTF,  show_probability_plot=False, print_results=False)  # fit the Weibull_3P distribution
print('Fit_Weibull_3P parameters:\nAlpha:', wbf.alpha, '\nBeta:', wbf.beta, '\nGamma', wbf.gamma)
histogram(TTF,bins=30) # generates the histogram using optimal bin width and shades the censored part as white
#dist.PDF(label='True Distribution')  # plots the true distribution's PDF
wbf.distribution.PDF( linestyle='-')  # plots to PDF of the fitted Weibull_3P
plt.title('Histogram of Time to System Failure ')
plt.xlabel("TTF (Hours)")
plt.ylabel("Frequency")

plt.sca(axs[0][1])
plt.hist(TTF,cumulative=-1,density=True,stacked=True, bins=100,color='lightgrey')
#wbf.distribution.SF(label='fitted distribution',color='b')
plt.title('Cumulative Distribution Function of System Failure')
plt.xlabel("TTF (Hours)")
plt.ylabel("Probability")
#plt.show()



df = pd.read_csv('10/fft.csv', sep=',',index_col=0)

FFT = np.array(df['FFT2'])



plt.sca(axs[1][0])
wbf = Fit_Weibull_3P(failures=FFT,  show_probability_plot=False, print_results=False)  # fit the Weibull_3P distribution
print('Fit_Weibull_3P parameters:\nAlpha:', wbf.alpha, '\nBeta:', wbf.beta, '\nGamma', wbf.gamma)
histogram(FFT,bins=30) # generates the histogram using optimal bin width and shades the censored part as white
#dist.PDF(label='True Distribution')  # plots the true distribution's PDF
wbf.distribution.PDF( linestyle='-')  # plots to PDF of the fitted Weibull_3P
plt.title('Histogram of Time to Failure of First Core ')
plt.xlabel("TTF (Hours)")
plt.ylabel("Frequency")

plt.sca(axs[1][1])
plt.hist(FFT,cumulative=-1,density=True,stacked=True, bins=100,color='lightgrey')
#wbf.distribution.SF(label='fitted distribution',color='b')
plt.title('Cumulative Distribution Function of First Core Failure')
plt.xlabel("TTF (Hours)")
plt.ylabel("Probability")
#plt.show()






##data = TTF
##plt.plot(data, stats.exponweib.pdf(data, *stats.exponweib.fit(data, 1, 1, scale=2, loc=0)),'r')
##_ = plt.hist(data, bins=50, normed=True, alpha=0.5);
##plt.show()

##plt.plot(x)
##plt.show()
#plt.rcParams.update({'font.size': 20})
#fig, axs = plt.subplots(2,2)
#fig.suptitle('Time to Failure')

##axs[0].plot(TTF, st.exponweib.pdf(TTF, *stats))
#axs[0][0].hist(TTF,density=False, bins=50)
#axs[1][0].hist(FFT,density=False, bins=50)

##print(bins)
##plt.sca(axs[0])
##mn, mx = plt.xlim()
##axs[0].set_xlim(mn, mx)
##kde_xs = np.linspace(mn, mx, 300)
##kde = st.exponweib.pdf(TTF)
##axs[0].plot(kde_xs, kde.pdf(kde_xs), label="PDF")
##plt.legend(loc="upper left")
#axs[0][0].set_ylabel("Frequency")
#axs[0][0].set_xlabel("TTF (Hours)")
#axs[0][0].set_title("System Failure Histogram");
#axs[1][0].set_ylabel("Frequency")
#axs[1][0].set_xlabel("TTF (Hours)")
#axs[1][0].set_title("First Failure Histogram");

#axs[0][1].hist(TTF,cumulative=-1,density=True,stacked=True, bins=100)
#axs[0][1].set_ylabel("Probability")
#axs[0][1].set_xlabel("TTF (Hours)")
#axs[0][1].set_title("System Failure Cumulative Distribution Function");

#axs[1][1].hist(FFT,cumulative=-1,density=True,stacked=True, bins=100)
#axs[1][1].set_ylabel("Probability")
#axs[1][1].set_xlabel("TTF (Hours)")
#axs[1][1].set_title("First Failure Cumulative Distribution Function");


######
##dfm = pd.read_csv('ttf.csv', sep=',',index_col=0)

##TTFm = dfm['ttf']
##FFTm = dfm['fft']
##stats = st.exponweib.fit(TTFm, 0, 0, scale=1, loc=0)
##print("stats:",st.exponweib.pdf(TTFm, *stats))
###plt.plot(st.exponweib.pdf(TTF, *stats))
###plt.show()


###axs[0].plot(TTF, st.exponweib.pdf(TTF, *stats))
##axs[0][0].hist(TTFm,density=False, bins=50)
##axs[1][0].hist(FFTm,density=False, bins=50)

###print(bins)
###plt.sca(axs[0])
###mn, mx = plt.xlim()
###axs[0].set_xlim(mn, mx)
###kde_xs = np.linspace(mn, mx, 300)
###kde = st.exponweib.pdf(TTF)
###axs[0].plot(kde_xs, kde.pdf(kde_xs), label="PDF")
###plt.legend(loc="upper left")

##axs[0][1].hist(TTFm,cumulative=-1,density=True,stacked=True, bins=100)


##axs[1][1].hist(FFTm,cumulative=-1,density=True,stacked=True, bins=100)


plt.sca(axs[0][0])
mn, mx = plt.ylim()
y_ave_hist_ttf = np.linspace(mn, mx, 3)



plt.sca(axs[1][0])
mn, mx = plt.ylim()
y_ave_hist_fft = np.linspace(mn, mx, 3)

y_ave_cdf = np.linspace(0, 1, 3)

x_ave_ttf = np.ones(3)*np.average(TTF)
x_ave_fft = np.ones(3)*np.average(FFT)

axs[0][0].plot(x_ave_ttf,y_ave_hist_ttf,'navy',linestyle='dashed',label="MTTF")
axs[0][1].plot(x_ave_ttf,y_ave_cdf,'navy',linestyle='dashed',label="MTTF")
axs[1][0].plot(x_ave_fft,y_ave_hist_fft,'navy',linestyle='dashed',label="MTTF")
axs[1][1].plot(x_ave_fft,y_ave_cdf,'navy',linestyle='dashed',label="MTTF")


axs[0][0].legend()
axs[0][1].legend()
axs[1][0].legend()
axs[1][1].legend()

plt.show()
#aaa = np.cumsum(-bins)
#plt.plot(aaa)
#plt.show()

#cy = np.cumsum(TTF)
#plt.plot(cy)
#plt.show()
