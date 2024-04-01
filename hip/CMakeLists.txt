find_package(TBB)
if(TBB_FOUND)
	add_executable(example1hip MatrixTranspose.cpp)
	target_include_directories(example1hip PUBLIC 
										   "../thirdparty/HIP-CPU/include/")
    target_link_libraries(example1hip TBB::tbb)
    
    add_test(NAME "example1 HIP" COMMAND example1hip)
endif()
