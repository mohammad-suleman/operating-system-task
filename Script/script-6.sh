#!/bin/bash
echo "for Loop"
printf "enter the no which table u want "
read x
y=1
k=0
echo "Multiplication table of $x is as below"

for ((y=1;y<=10;y++)) do
k=$(( $x * $y )) 
echo "$x X $y=$k"
done
exit 0 