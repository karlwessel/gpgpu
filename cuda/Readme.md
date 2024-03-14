This contains examples using CUDA and CUDA converted to HIP.

# Setup
To be able to compile cuda the cuda compiler is needed. With Arch linux it can be installed with
 `pacman -S cuda`.

## Compile HIPIFY
To convert the cuda code to HIP the HIPIFY-clang tool is used. Since the version from the Arch repository fails (see issue [3]) one has to compile the one contained in `thirdparty/HIPIFY`.

Requirements: llvm, cmake
Under Arch these can be installed with
 `pacman -S llvm cmake`

To compile switch to the `thirdparty/HIPIFY` directory and do
 ```
 git submodule init
 git submodule fetch
 git checkout fixfordynamicllvm
 cmake -B ../HIPIFYbuild -DCMAKE_INSTALL_PREFIX=../HIPIFYdist -DCMAKE_BUILD_TYPE=Release .
 cd ../HIPIFYbuild
 make install
```

## Fetch HIP-CPU
See readme for HIP examples `hip/Readme.md`.

# Compile
See the `Makefile` on how to convert cuda to HIP files and how to run them.

# Execute
For executing binaries compiled using chipStar see the Readme.md for hip examples.
