hipfile = saxpy.cpp
clangdir = /opt/rocm/lib/llvm/lib/clang/17.0.0/
# clangdir = /usr/lib/clang/17/

all: saxpycuda saxpyhip saxpychip

saxpycuda: saxpy.cu
	nvcc saxpy.cu -o saxpycuda

saxpychip: saxpy.cu
	../thirdparty/chipStar/install/bin/cuspvc -O3 saxpy.cu -o saxpychip

saxpyhip: $(hipfile)
	g++ -O3 -I../thirdparty/HIP-CPU/include/ $(hipfile) -ltbb -o saxpyhip

$(hipfile): saxpy.cu
	../thirdparty/HIPIFYdist/bin/hipify-clang saxpy.cu --clang-resource-directory=$(clangdir) --hip-kernel-execution-syntax -o $(hipfile)

.PHONY : clean
clean:
	rm -f saxpycuda
	rm -f saxpyhip
	rm -f $(hipfile)
	rm -f saxpychip



	
