all: example1 saxpy

example1: example1.c
	gcc -fopenmp example1.c -o example1

saxpy: saxpy.cpp
	g++ -O3 -fopenmp saxpy.cpp -o saxpy
