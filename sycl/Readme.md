Test project for SYCL

# Setup
- Install Intels OneAPI C++ compiler:
   `pacman -S intel-oneapi-dpcpp-cpp`

# Compile
To compile with SYCL support using OneAPI compiler first laod environment with
 `source /opt/intel/oneapi/setvars.sh`
then compile with
 `icpx -fsycl main.cpp`.
 
Or just run the Makefile with
 `make`

# Ressources
- Setup on arch linux: https://wiki.archlinux.org/title/GPGPU#SYCL
- Intels OneAPI C++ compiler for SYCL:
- Getting started with Intels OneAPI C++ compiler for SYCL: https://www.intel.com/content/www/us/en/developer/tools/oneapi/dpc-compiler.html
