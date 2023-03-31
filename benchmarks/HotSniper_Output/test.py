import os 

for subdir, dirs, files in os.walk("./"):
#	print(subdir)
#	print("--------")
	for dire in dirs:
		if dire[0:6] == "result":
			print(subdir + os.sep +dire)
			benchmark = subdir[1:]
			freq = dire[25:31]
			filepath = "../powertraces"+benchmark+"/"+freq
#			print("filepath: ", filepath)
#	print("--------\n")
#	for file in files:
#        #print os.path.join(subdir, file)
#		filepath = subdir + os.sep + file

##        if filepath.endswith(".asm"):
#		print (filepath)

