import sniper_stats
stats = sniper_stats.SniperStats(resultsdir = resultsdir, jobid = jobid)
#try:
markers = stats.get_markers()
#except Exception, e:
#	print >> sys.stderr, e
#	print >> sys.stderr, "--markers could not be fetched"
#	sys.exit(1)

for timestamp, core, thread, value0, value1, description in markers:
	print (timestamp, core, thread, value0, value1, description)
	
	

