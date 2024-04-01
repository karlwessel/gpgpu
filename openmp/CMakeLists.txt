find_package(OpenMP)
if(OpenMP_CXX_FOUND)
	add_executable(saxpyopenmp saxpy.cpp)
	target_compile_options(saxpyopenmp PUBLIC -O2)
	target_link_libraries(saxpyopenmp PUBLIC OpenMP::OpenMP_CXX)

	add_executable(example1openmp example1.c)
    target_link_libraries(example1openmp PUBLIC OpenMP::OpenMP_CXX)
    
    add_test(NAME "saxpy OpenMP" COMMAND saxpyopenmp)
	add_test(NAME "example1 OpenMP" COMMAND example1openmp)
endif()
