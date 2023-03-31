BENCH:=beamformer_12c_4b
BENCHSRCFILE:=$(SRC_DIR)/BeamFormer/BeamFormer_12c_4b.c
BENCHHFILE:=$(SRC_DIR)/BeamFormer/BeamFormer_12c_4b.h
BENCHEXTRAFLAGS:=-DBUF_SIZEMAX=48

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))

BENCH:=sdf_beamformer_nocache
BENCHSRCFILE:=$(SRC_DIR)/BeamFormer/SDF-BeamFormer_nocache.c
BENCHHFILE:=$(SRC_DIR)/BeamFormer/SDF-BeamFormer_nocache.h

$(eval $(call BENCH_TEMPLATE, $(BENCH), $(BENCHSRCFILE), $(BENCHHFILE), $(BENCHEXTRAFLAGS)))