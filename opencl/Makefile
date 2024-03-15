all: HelloOpenCL saxpy

saxpy : saxpy.cpp
	g++ -O3 -Wall -Wextra -D CL_TARGET_OPENCL_VERSION=300 saxpy.cpp -o saxpy -lOpenCL


HelloOpenCL : main.c
	gcc -Wall -Wextra -D CL_TARGET_OPENCL_VERSION=300 main.c -o HelloOpenCL -lOpenCL

%PHONY: clean
clean: 
	rm -f HelloOpenCL
	rm -f saxpy
