This contains examples using HIP.

# Setup
There are two ways to compile HIP code without ROCm hardware.
1. HIP-CPU: easy to use, header only library
2. chipStar: needs llvm but can also execute CUDA source files and uses OpenCL to run on any OpenCL compatible device.

## HIP-CPU
The makefiles currently uses the hardware independent HIP-CPU runtime to compile HIP examples. It is contained in the repository as a submodule under `thirdparty/HIP-CPU`. You need to fetch it by running the following commands in that directory 
 ```
 git submodule init
 git submodule fetch
 ```
That runtime also need Intels oneAPI Threading Building Blocks (tbb) library. Under arch it should be installable as
 `pacman -S intel-oneapi-tbb`

## chipStar
Requirements: llvm 

Chipstar is included as a git submodule under `thirdparty/chipstar`. To build it you can try the following instructions or if it doesn't work see the project documentation:
 ```
 git submodule init
 git submodule fetch
 cmake .. -DLLVM_CONFIG_BIN=/usr/bin/llvm-config -DCMAKE_INSTALL_PREFIX=../install -DCHIP_BUILD_SAMPLES=OFF -DCHIP_BUILD_TESTS=OFF
 make -j install
 ```
 
# Compile
Using the OpenCL based chipStar the samples can be compiled with
 `../thirdparty/chipStar/install/bin/hipcc ./MatrixTranspose.cpp -o example1`.
 
Using the hardware independent HIP-CPU runtime samples can be compiled with
 `g++ -ltbb -I../thirdparty/HIP-CPU/include/ MatrixTranspose.cpp`.

Or just use the `Makefile`.

# Execute
To execute binaries compiled with chipStar on CPU-only devices you need to set the environment variable `CHIP_DEVICE_TYPE` accordingly
 `export CHIP_DEVICE_TYPE=cpu`.

# How to use without ROCm compatible hardware
- Hardware independent - HIP-CPU: <https://github.com/ROCm/HIP-CPU>
- Using OpenCL devices - chipStar: <https://github.com/CHIP-SPV/chipStar>
