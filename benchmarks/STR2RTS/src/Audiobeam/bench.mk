BENCH:=audiobeam_15mics
BENCHSRCFILE:=$(SRC_DIR)/Audiobeam/Audiobeam_15mics.c
BENCHHFILE:=$(SRC_DIR)/Audiobeam/Audiobeam_15mics.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=30

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=sdf_audiobeam_nocache
BENCHSRCFILE:=$(SRC_DIR)/Audiobeam/SDF-Audiobeam_nocache.c
BENCHHFILE:=$(SRC_DIR)/Audiobeam/SDF-Audiobeam_nocache.h

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))
