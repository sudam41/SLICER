BENCH:=sdf_transmit_nocache
BENCHSRCFILE:=$(SRC_DIR)/802.11a/SDF-transmit_nocache.c
BENCHHFILE:=$(SRC_DIR)/802.11a/SDF-transmit_nocache.h
BENCHEXTRAFLAGS:=$(shell grep "\-DBUF_SIZEMAX=" $(SRC_DIR)/802.11a/SDF-transmit_nocache.h | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=hsdf_transmit_nocache
BENCHSRCFILE:=$(SRC_DIR)/802.11a/HSDF-transmit_nocache.c
BENCHHFILE:=$(SRC_DIR)/802.11a/HSDF-transmit_nocache.h
BENCHEXTRAFLAGS:=$(shell grep "\-DBUF_SIZEMAX=" $(SRC_DIR)/802.11a/HSDF-transmit_nocache.h | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=sdf_transmit
BENCHSRCFILE:=$(SRC_DIR)/802.11a/SDF-transmit.c
BENCHHFILE:=$(SRC_DIR)/802.11a/SDF-transmit.h
BENCHEXTRAFLAGS:=$(shell grep "\-DBUF_SIZEMAX=" $(SRC_DIR)/802.11a/SDF-transmit.h | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=hsdf_transmit
BENCHSRCFILE:=$(SRC_DIR)/802.11a/HSDF-transmit.c
BENCHHFILE:=$(SRC_DIR)/802.11a/HSDF-transmit.h
BENCHEXTRAFLAGS:=$(shell grep "\-DBUF_SIZEMAX=" $(SRC_DIR)/802.11a/HSDF-transmit.h | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

#$(foreach b, $(shell ls $(SRC_DIR)/802.11a/PEGs/PEG*.h), \
   $(eval $(call BENCH_TEMPLATE, \
		 $(shell echo $$(basename -s'.h' $(b)) | tr A-Z a-z | tr - _), \
		 $(shell dirname $(b))/$(shell basename -s'.h' $(b)).c, \
		 $(b), \
		 $(shell grep "\-DBUF_SIZEMAX=" $(b) | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')))\
)

all_80211a: sdf_transmit_nocache hsdf_transmit_nocache sdf_transmit hsdf_transmit $(foreach b, $(shell ls $(SRC_DIR)/802.11a/PEGs/PEG*.h), $(shell echo $$(basename -s'.h' $(b)) | tr A-Z a-z | tr - _))
	