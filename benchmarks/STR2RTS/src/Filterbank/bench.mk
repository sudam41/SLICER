BENCH:=filterbank_8samp
BENCHSRCFILE:=$(SRC_DIR)/Filterbank/Filterbank_8samp.c
BENCHHFILE:=$(SRC_DIR)/Filterbank/Filterbank_8samp.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=256

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=sdf_filterbank_nocache
BENCHSRCFILE:=$(SRC_DIR)/Filterbank/SDF-FilterBankNew_nocache.c
BENCHHFILE:=$(SRC_DIR)/Filterbank/SDF-FilterBankNew_nocache.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=264

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=hsdf_filterbank_nocache
BENCHSRCFILE:=$(SRC_DIR)/Filterbank/HSDF-FilterBankNew_nocache.c
BENCHHFILE:=$(SRC_DIR)/Filterbank/HSDF-FilterBankNew_nocache.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=1598

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

#$(foreach b, $(shell ls $(SRC_DIR)/Filterbank/PEGs/PEG*.h), \
   $(eval $(call BENCH_TEMPLATE, \
		 $(shell echo $$(basename -s'.h' $(b)) | tr A-Z a-z | tr - _), \
		 $(shell dirname $(b))/$(shell basename -s'.h' $(b)).c, \
		 $(b), \
		 $(shell grep "\-DBUF_SIZEMAX=" $(b) | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')))\
)