cmake_minimum_required(VERSION 3.19...3.29)
project(gpgpu LANGUAGES C CXX)

include(CTest)

# Update submodules as needed
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
	option(GIT_SUBMODULE "Check submodules during build" ON)
	if(GIT_SUBMODULE)
	    message(STATUS "Submodule update")
	    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
	                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
	    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
	        message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
	    endif()
	endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/thirdparty/HIPIFY/CMakeLists.txt")
	message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# add hipify as external project
include(ExternalProject)
ExternalProject_Add(hipify PREFIX thirdparty/HIPIFY
						   SOURCE_DIR ${PROJECT_SOURCE_DIR}/thirdparty/HIPIFY
						   CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
						   BINARY_DIR thirdparty/HIPIFYbuild
						   INSTALL_DIR thirdparty/HIPIFYdist)

# define executable targets to be compiled with HIP-CPU
function(add_hipcpu_executable name)
  # Forward all parameters to add_executable
  add_executable(${ARGV})
  
  # Perform additional actions
  target_link_libraries(${name} PRIVATE TBB::tbb)
  target_include_directories(${name} PRIVATE 
								"../thirdparty/HIP-CPU/include/")
endfunction()

add_subdirectory(openmp)

add_subdirectory(opencl)

add_subdirectory(hip)

add_subdirectory(cuda)



