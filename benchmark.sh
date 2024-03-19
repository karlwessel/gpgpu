#!/bin/bash

format="%C %e %x"

for binary in opencl/saxpy cuda/saxpychip cuda/saxpyhip
do
	echo "Testing $binary"
	for i in $(seq 15 19);
	do
		echo "2^$i"
		time -f"$format" -a -obenchmark.csv ./$binary $i
	done
done

for binary in juliaoneapi/scripts/saxpy.sh opencl/saxpy cuda/saxpychip cuda/saxpyhip
do
	echo "Testing $binary"
	for i in $(seq 20 28);
	do
		echo "2^$i"
		time -f"$format" -a -obenchmark.csv ./$binary $i
	done
done

for binary in juliaoneapi/scripts/saxpy.sh opencl/saxpy cuda/saxpychip
do
	echo "Testing $binary"
	for i in $(seq 26 29);
	do
		echo "2^$i"
		time -f"$format" -a -obenchmark.csv ./$binary $i
	done
done
