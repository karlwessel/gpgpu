SHELL := /bin/bash # make source available

all: example1 example2

example1 : example1.cpp
	source /opt/intel/oneapi/setvars.sh && icpx -fsycl example1.cpp -o example1

example2 : example2.cpp
	source /opt/intel/oneapi/setvars.sh && icpx -fsycl example2.cpp -o example2
