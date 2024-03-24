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

# Troubleshooting
- Intel Graphics not detected by OpenCL (not listed in clinfo):
  - seems to be an issue with linux kernel>=6.8:
    <https://github.com/intel/compute-runtime/issues/710>
  - workaround is to export the following environment variables:
    ```
    export NEOReadDebugKeys=1
    export OverrideGpuAddressSpace=48
    ```

# Ressources
- Setup on arch linux: <https://wiki.archlinux.org/title/GPGPU#OpenCL>
- Simple example file can be taken from: <https://github.com/KhronosGroup/OpenCL-Guide/blob/main/chapters/getting_started_linux.md#invoking-the-compiler-manually>
