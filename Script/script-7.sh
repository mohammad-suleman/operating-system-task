#!/bin/bash
echo "Switch statement"
x=$1
case $x in
    1)
        echo "this is level 1"
        ;;
    2)  
        echo "this is level 2"
        ;;
    3)
        echo "this is level 3"
        ;;
    *)
        echo "this is my default level"
        ;;
esac
exit 0
