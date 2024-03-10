hipfile = saxpy.cpp
clangdir = /opt/rocm/lib/llvm/lib/clang/17.0.0/
# clangdir = /usr/lib/clang/17/

all: example1cuda example1hip

example1cuda: saxpy.cu
	nvcc saxpy.cu -o example1cuda

example1hip: $(hipfile)
	g++ -I../thirdparty/HIP-CPU/include/ $(hipfile) -ltbb -o example1hip
	
$(hipfile): saxpy.cu
	../thirdparty/HIPIFYdist/bin/hipify-clang saxpy.cu --clang-resource-directory=$(clangdir) --hip-kernel-execution-syntax -o $(hipfile)

.PHONY : clean
clean:
	rm -f example1cuda
	rm -f example1hip
	rm -f $(hipfile)



	
