cmake_minimum_required(VERSION 3.19...3.29)
project(gpgpu LANGUAGES C CXX)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
	add_executable(saxpyopenmp openmp/saxpy.cpp)
	target_compile_options(saxpyopenmp PUBLIC -O2)
	target_link_libraries(saxpyopenmp PUBLIC OpenMP::OpenMP_CXX)

	add_executable(example1openmp openmp/example1.c)
    target_link_libraries(example1openmp PUBLIC OpenMP::OpenMP_CXX)
endif()

find_package(OpenCL)
if(OpenCL_FOUND)
	add_executable(saxpyopencl opencl/saxpy.cpp)
	target_compile_options(saxpyopencl PUBLIC -O2 -DCL_TARGET_OPENCL_VERSION=300)
	target_link_libraries(saxpyopencl PUBLIC OpenCL::OpenCL)

	add_executable(example1opencl opencl/main.c)
	target_compile_options(saxpyopencl PUBLIC -DCL_TARGET_OPENCL_VERSION=300)
    target_link_libraries(example1opencl PUBLIC OpenCL::OpenCL)
endif()
