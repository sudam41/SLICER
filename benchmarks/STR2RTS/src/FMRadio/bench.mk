BENCH:=fmradio_7bands
BENCHSRCFILE:=$(SRC_DIR)/FMRadio/FMRadio_7bands.c
BENCHHFILE:=$(SRC_DIR)/FMRadio/FMRadio_7bands.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=512

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=sdf_fmradio_nocache
BENCHSRCFILE:=$(SRC_DIR)/FMRadio/SDF-FMRadio_nocache.c
BENCHHFILE:=$(SRC_DIR)/FMRadio/SDF-FMRadio_nocache.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=4485

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))
