AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = example1openmp saxpyopenmp
TESTS = saxpyopenmp example1openmp
if USE_OPENCL
  bin_PROGRAMS += saxpyopencl example1opencl
  TESTS += saxpyopencl example1opencl
endif
example1openmp_SOURCES = openmp/example1.c
saxpyopenmp_SOURCES = openmp/saxpy.cpp
saxpyopencl_SOURCES = opencl/saxpy.cpp
example1opencl_SOURCES = opencl/main.c

saxpyopencl_CPPFLAGS = -DCL_TARGET_OPENCL_VERSION=300
example1opencl_CPPFLAGS = -DCL_TARGET_OPENCL_VERSION=300

