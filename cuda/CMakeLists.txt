find_package(TBB)
find_package(Clang)

if(TBB_FOUND AND CLANG_INSTALL_PREFIX)
	# path to external module HIPIFY
	ExternalProject_Get_Property(hipify install_dir)
	message("HIPIFY path: ${install_dir}")
	
	# get Clang ressource path needed by hipify-clang command
	find_program(clang clang "${CLANG_INSTALL_PREFIX}/bin/" NO_CACHE NO_DEFAULT_PATH)
	execute_process(COMMAND clang -print-resource-dir 
					OUTPUT_VARIABLE CLANG_RESOURCE_DIR
					OUTPUT_STRIP_TRAILING_WHITESPACE)
	message("Found Clang ressource dir: ${CLANG_RESOURCE_DIR}")
	set(HIPIFY_FOUND yes)
endif()

function(hipify in out)
  	add_custom_command(
  		OUTPUT ${out}
  		DEPENDS ${in} hipify
  		VERBATIM
  		COMMAND ${install_dir}/bin/hipify-clang
  			    ${in}
  			    --clang-resource-directory=${CLANG_RESOURCE_DIR}/
  			    --hip-kernel-execution-syntax
  			    -o ${out}
	)
endfunction()

if(HIPIFY_FOUND)
	# convert saxpy.cu to HIP code
	hipify(${CMAKE_CURRENT_SOURCE_DIR}/saxpy.cu saxpy.cpp)
	
	# compile converted hip code using HIP-CPU
	add_hipcpu_executable(saxpyhipify "saxpy.cpp")

	add_test(NAME "saxpy HIPIFYCPU" COMMAND saxpyhipify)
endif()
