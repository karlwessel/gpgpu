SHELL := /bin/bash # make source available

all: saxpy example1 example2

example1 : example1.cpp
	source /opt/intel/oneapi/setvars.sh && icpx -fsycl example1.cpp -o example1

example2 : example2.cpp
	source /opt/intel/oneapi/setvars.sh && icpx -fsycl example2.cpp -o example2

saxpy : saxpy.cpp
	source /opt/intel/oneapi/setvars.sh && icpx -fsycl -O3 saxpy.cpp -o saxpy
