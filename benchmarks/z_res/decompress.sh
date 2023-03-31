#for d in /home/sudam/Simuflage/Simuflage2.0/util/str2rts_res/*; do
#  if [ -d "$d" ]; then
#    echo "$d"
#  fi
#done


for d in $(find /home/sudam//Simuflage/Simuflage2.0/benchmarks/z_res/ -maxdepth 2 -type d)
do
	#Do something, the directory is accessible with $d:
	echo $d
	cd $d
	gzip -d PeriodicPower.log.gz

done
