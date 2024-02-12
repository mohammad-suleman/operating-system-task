#!/bin/bash

echo "While Loop"
x=1

while [ $x -gt 1 ] ; do
	echo $x
	x=$(( $x - 1 ))
done
exit 0