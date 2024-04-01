find_package(OpenCL)
if(OpenCL_FOUND)
	add_executable(saxpyopencl saxpy.cpp)
	target_compile_options(saxpyopencl PUBLIC -O2 -DCL_TARGET_OPENCL_VERSION=300)
	target_link_libraries(saxpyopencl PUBLIC OpenCL::OpenCL)

	add_executable(example1opencl main.c)
	target_compile_options(saxpyopencl PUBLIC -DCL_TARGET_OPENCL_VERSION=300)
    target_link_libraries(example1opencl PUBLIC OpenCL::OpenCL)
    
    add_test(NAME "saxpy OpenCL" COMMAND saxpyopencl)
	add_test(NAME "example1 OpenCL" COMMAND example1opencl)
endif()
