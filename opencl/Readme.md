Test project for OpenCL

# Setup
- Install an OpenCL runtime, a hardware independent one is pocl:
   `pacman -S pocl`
- Install header files:
   `pacman -S opencl-headers`

# Compile
Compile with
 `gcc -lOpenCL main.c`,
 
Or just run the Makefile with
 `make`.

# Ressources
- Setup on arch linux: <https://wiki.archlinux.org/title/GPGPU#OpenCL>
- Simple example file can be taken from: <https://github.com/KhronosGroup/OpenCL-Guide/blob/main/chapters/getting_started_linux.md#invoking-the-compiler-manually>
