#!/bin/sh
a=0

while [ $a -lt 20 ]
do
	./test_gnl sample
	   a=$((a+1))
done

