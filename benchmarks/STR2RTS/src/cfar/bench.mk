BENCH:=cfar
BENCHSRCFILE:=$(SRC_DIR)/cfar/CFAR.c
BENCHHFILE:=$(SRC_DIR)/cfar/CFAR.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=256

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=sdf_cfartest_nocache
BENCHSRCFILE:=$(SRC_DIR)/cfar/SDF-CFARtest_nocache.c
BENCHHFILE:=$(SRC_DIR)/cfar/SDF-CFARtest_nocache.h
BENCHEXTRAFLAGS:=$(shell grep "\-DBUF_SIZEMAX=" $(SRC_DIR)/cfar/SDF-CFARtest_nocache.h | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=hsdf_cfartest_nocache
BENCHSRCFILE:=$(SRC_DIR)/cfar/HSDF-CFARtest_nocache.c
BENCHHFILE:=$(SRC_DIR)/cfar/HSDF-CFARtest_nocache.h
BENCHEXTRAFLAGS:=$(shell grep "\-DBUF_SIZEMAX=" $(SRC_DIR)/cfar/HSDF-CFARtest_nocache.h | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=sdf_cfartest
BENCHSRCFILE:=$(SRC_DIR)/cfar/SDF-CFARtest.c
BENCHHFILE:=$(SRC_DIR)/cfar/SDF-CFARtest.h
BENCHEXTRAFLAGS:=$(shell grep "\-DBUF_SIZEMAX=" $(SRC_DIR)/cfar/SDF-CFARtest.h | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=hsdf_cfartest
BENCHSRCFILE:=$(SRC_DIR)/cfar/HSDF-CFARtest.c
BENCHHFILE:=$(SRC_DIR)/cfar/HSDF-CFARtest.h
BENCHEXTRAFLAGS:=$(shell grep "\-DBUF_SIZEMAX=" $(SRC_DIR)/cfar/HSDF-CFARtest.h | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

#$(foreach b, $(shell ls $(SRC_DIR)/cfar/PEGs/PEG*.h), \
   $(eval $(call BENCH_TEMPLATE, \
		 $(shell echo $$(basename -s'.h' $(b)) | tr A-Z a-z | tr - _), \
		 $(shell dirname $(b))/$(shell basename -s'.h' $(b)).c, \
		 $(b), \
		 $(shell grep "\-DBUF_SIZEMAX=" $(b) | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')))\
)

all_cfar: cfar sdf_cfartest_nocache hsdf_cfartest_nocache sdf_cfartest hsdf_cfartest $(foreach b, $(shell ls $(SRC_DIR)/cfar/PEGs/PEG*.h), $(shell echo $$(basename -s'.h' $(b)) | tr A-Z a-z | tr - _))
	