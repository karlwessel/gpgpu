all: example1 example1chip

example1 : MatrixTranspose.cpp
	g++ -I../thirdparty/HIP-CPU/include/ MatrixTranspose.cpp -ltbb -o example1

example1chip : MatrixTranspose.cpp
	../thirdparty/chipStar/install/bin/hipcc ./MatrixTranspose.cpp -o example1chip

%PHONY: clean

clean:
	rm -f saxpy
	rm -f example1
	rm -f example1chip
