#!/bin/bash
echo "if-else(Conditional statement)"
# ####################

#######################
big_num()
{
    x=$1
    y=$2
    z=$3

    if [ $x -gt $y ] ; then
        if [ $x -gt $z ] ; then
            echo "Biggest no is:$x"
        else
            echo "Biggest no is:$z"
        fi
    else
        if [ $y -gt $z ] ; then
            echo "In Y: Biggest no is:$y"
        else
            echo "In Z: Biggest no  is:$z"
        fi
    fi
}
    big_num 2 8 8
    exit 0