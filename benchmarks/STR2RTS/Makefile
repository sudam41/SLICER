TARGET=filterbank_1

# Compile only, we need to run using simulationcontrol.
all: $(TARGET)

include ../shared/Makefile.shared

##FFT2
#$(TARGET):
#	cc $(SNIPER_CFLAGS) $(SNIPER_LDFLAGS) -Wfatal-errors -g -std=c11 -DBUF_SIZEMAX=512 -I src -o $@ src/fft/SDF-FFT2_nocache_new.c src/comm_shared_buffer.c src/globals.c  -lm

##FFT4	
#$(TARGET):
#	cc $(SNIPER_CFLAGS) $(SNIPER_LDFLAGS) -Wfatal-errors -g -std=c11 -DBUF_SIZEMAX=4 -I src -o $@ src/fft/SDF-FFT4_nocache_new.c src/comm_shared_buffer.c src/globals.c  -lm

#FilBank	
$(TARGET):
	cc $(SNIPER_CFLAGS) $(SNIPER_LDFLAGS) -Wfatal-errors -g -std=c11 -DBUF_SIZEMAX=264 -I src -o $@ src/Filterbank/SDF-FilterBankNew_nocache_new.c src/comm_shared_buffer.c src/globals.c  -lm

##FMR	
#$(TARGET):
#	cc $(SNIPER_CFLAGS) $(SNIPER_LDFLAGS) -Wfatal-errors -g -std=c11 -DBUF_SIZEMAX=4485 -I src -o $@ src/FMRadio/SDF-FMRadio_nocache_new.c src/comm_shared_buffer.c src/globals.c  -lm

###802
#$(TARGET):
#	cc $(SNIPER_CFLAGS) $(SNIPER_LDFLAGS) -Wfatal-errors -g -std=c11 -DBUF_SIZEMAX=6912 -I src -o $@ src/802.11a/SDF-transmit_nocache_new.c src/comm_shared_buffer.c src/globals.c  -lm

###des
#$(TARGET):
#	cc $(SNIPER_CFLAGS) $(SNIPER_LDFLAGS) -Wfatal-errors -g -std=c11 -DBUF_SIZEMAX=6912 -I src -o $@ src/des/SDF-DES_nocache_new.c src/comm_shared_buffer.c src/globals.c  -lm

###Audiobeam
#$(TARGET):
#	cc $(SNIPER_CFLAGS) $(SNIPER_LDFLAGS) -Wfatal-errors -g -std=c11 -DBUF_SIZEMAX=6912 -I src -o $@ src/Audiobeam/SDF-Audiobeam_nocache.c src/comm_shared_buffer.c src/globals.c  -lm
#	
###dct
#$(TARGET):
#	cc $(SNIPER_CFLAGS) $(SNIPER_LDFLAGS) -Wfatal-errors -g -std=c11 -DBUF_SIZEMAX=6912 -I src -o $@ src/dct/SDF-iDCTcompare_nocache_new.c src/comm_shared_buffer.c src/globals.c  -lm

###cfar
#$(TARGET):
#	cc $(SNIPER_CFLAGS) $(SNIPER_LDFLAGS) -Wfatal-errors -g -std=c11 -DBUF_SIZEMAX=6912 -I src -o $@ src/cfar/SDF-CFARtest_nocache_new.c src/comm_shared_buffer.c src/globals.c  -lm

##$(TARGET)_uftrace:
##	cc $(SNIPER_CFLAGS) -finstrument-functions -Wfatal-errors -g -std=c11 -DBUF_SIZEMAX=48 -I src -o $@ src/des/SDF-DES_nocache_ori_withmarkers.c src/comm_shared_buffer.c src/globals.c  -lm
#	
## removed --roi because we lack the markers
## Try: -n 2 to use two cores
#run_$(TARGET):
#	../../run-sniper -v -n 1 -s markers:verbose:markers -c gainestown -- ./bin/des_16
#	#../../run-sniper -v -n 2 -c gainestown -- ./beamformer_12c_4b

#CLEAN_EXTRA=$(TARGET)_uftrace
