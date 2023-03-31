BENCH:=des_16rounds
BENCHSRCFILE:=$(SRC_DIR)/des/DES_16rounds.c
BENCHHFILE:=$(SRC_DIR)/des/DES_16rounds.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=256

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=sdf_des_nocache
BENCHSRCFILE:=$(SRC_DIR)/des/SDF-DES_nocache.c
BENCHHFILE:=$(SRC_DIR)/des/SDF-DES_nocache.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=192

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=hsdf_des_nocache
BENCHSRCFILE:=$(SRC_DIR)/des/HSDF-DES_nocache.c
BENCHHFILE:=$(SRC_DIR)/des/HSDF-DES_nocache.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=128

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

#$(foreach b, $(shell ls $(SRC_DIR)/des/PEGs/PEG*.h), \
   $(eval $(call BENCH_TEMPLATE, \
		 $(shell echo $$(basename -s'.h' $(b)) | tr A-Z a-z | tr - _), \
		 $(shell dirname $(b))/$(shell basename -s'.h' $(b)).c, \
		 $(b), \
		 $(shell grep "\-DBUF_SIZEMAX=" $(b) | sed -e 's/.*\(-DBUF_SIZEMAX=[0-9]*\).*/\1/')))\
)