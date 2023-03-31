BENCH:=dct2
BENCHSRCFILE:=$(SRC_DIR)/dct/DCT2.c
BENCHHFILE:=$(SRC_DIR)/dct/DCT2.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=256 -DMAX_DATAREAD_IN_FILE=256 -DMAX_DATAWRITE_IN_FILE=256

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=sdf_idctcompare_nocache
BENCHSRCFILE:=$(SRC_DIR)/dct/SDF-iDCTcompare_nocache.c
BENCHHFILE:=$(SRC_DIR)/dct/SDF-iDCTcompare_nocache.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=384

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=hsdf_idctcompare_nocache
BENCHSRCFILE:=$(SRC_DIR)/dct/HSDF-iDCTcompare_nocache.c
BENCHHFILE:=$(SRC_DIR)/dct/HSDF-iDCTcompare_nocache.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=384

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=sdf_dctverify_nocache
BENCHSRCFILE:=$(SRC_DIR)/dct/SDF-DCTverify_nocache.c
BENCHHFILE:=$(SRC_DIR)/dct/SDF-DCTverify_nocache.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=256

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

#$(foreach b, $(shell ls $(SRC_DIR)/dct/PEGs/PEG*.h), \
   $(eval $(call BENCH_TEMPLATE, \
		 $(shell echo $$(basename -s'.h' $(b)) | tr A-Z a-z | tr - _), \
		 $(shell dirname $(b))/$(shell basename -s'.h' $(b)).c, \
		 $(b), \
		 $(shell grep "\-DBUF_SIZEMAX=" $(b) | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')))\
)