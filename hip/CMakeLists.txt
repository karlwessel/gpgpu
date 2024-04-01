find_package(TBB)
if(TBB_FOUND)
	add_hipcpu_executable(example1hip MatrixTranspose.cpp)
    
    add_test(NAME "example1 HIP" COMMAND example1hip)
endif()
