SHELL := /bin/bash # make source available

sycl : main.cpp
	source /opt/intel/oneapi/setvars.sh && icpx -fsycl main.cpp -o sycl

example2 : example2.cpp
	source /opt/intel/oneapi/setvars.sh && icpx -fsycl -g example2.cpp -o example2
