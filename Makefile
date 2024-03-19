
%PHONY: benchmark

benchmark: cuda/saxpychip cuda/saxpyhip opencl/saxpy
	sh benchmark.sh

cuda/saxpychip cuda/saxpyhip &: cuda/saxpy.cu
	make -C cuda

opencl/saxpy : opencl/saxpy.cpp
	make -C opencl
