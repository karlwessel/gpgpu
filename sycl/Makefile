SHELL := /bin/bash # make source available

sycl : main.cpp
	source /opt/intel/oneapi/setvars.sh && icpx -fsycl main.cpp -o sycl
