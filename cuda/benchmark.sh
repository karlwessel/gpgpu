#!/bin/bash

format="%C %e %x"

for binary in example1chip example1hip
do
	echo "Testing $binary"
	for i in $(seq 15 28);
	do
		echo "2^$i"
		time -f"$format" -a -obenchmark.csv ./$binary $i
	done
done

for binary in example1chip
do
	echo "Testing $binary"
	for i in $(seq 26 30);
	do
		echo "2^$i"
		time -f"$format" -a -obenchmark.csv ./$binary $i
	done
done
