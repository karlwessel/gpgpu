cmake_minimum_required(VERSION 3.19...3.29)
project(gpgpu LANGUAGES C CXX CUDA)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
	add_executable(saxpyopenmp openmp/saxpy.cpp)
	target_compile_options(saxpyopenmp PUBLIC -O2)
	target_link_libraries(saxpyopenmp PUBLIC OpenMP::OpenMP_CXX)

	add_executable(example1openmp openmp/example1.c)
    target_link_libraries(example1openmp PUBLIC OpenMP::OpenMP_CXX)
endif()
