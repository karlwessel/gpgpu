This contains examples using HIP.

# Setup
The makefiles currently uses the hardware independent HIP-CPU runtime to compile HIP examples. It is contained in the repository as a submodule under `thirdparty/HIP-CPU`. You need to fetch it by running the following commands in that directory 
 ```
 git submodule init
 git submodule fetch
 ```
That runtime also need Intels oneAPI Threading Building Blocks (tbb) library. Under arch it should be installable as
 `pacman -S intel-oneapi-tbb`

# Compile
Using the hardware independent HIP-CPU runtime samples can be compiled with
 `g++ -ltbb -I../thirdparty/HIP-CPU/include/ MatrixTranspose.cpp`

Or just use the `Makefile`.

# How to use without ROCm compatible hardware
- Hardware independent - HIP-CPU: <https://github.com/ROCm/HIP-CPU>
- Using OpenCL devices - chipStar: <https://github.com/CHIP-SPV/chipStar>
