Test project for SYCL

# Setup
- Install Intels OneAPI C++ compiler and the runtime:
   `pacman -S intel-oneapi-dpcpp-cpp intel-compute-runtime`

# Compile
To compile with SYCL support using OneAPI compiler first load environment with
 `source /opt/intel/oneapi/setvars.sh`
then compile with
 `icpx -fsycl main.cpp`.
 
Or just run the Makefile with
 `make`

# Run
First load environment with
 `source /opt/intel/oneapi/setvars.sh`
then you should be able to execute the examples.

# Ressources
- Setup on arch linux: <https://wiki.archlinux.org/title/GPGPU#SYCL>
- Intels OneAPI C++ compiler for SYCL:
- Getting started with Intels OneAPI C++ compiler for SYCL: <https://www.intel.com/content/www/us/en/developer/tools/oneapi/dpc-compiler.html>
- A simple test file can be taken from <https://github.com/intel/llvm/blob/sycl/sycl/doc/GetStartedGuide.md#run-simple-dpc-application>
