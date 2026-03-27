#!/bin/bash

clear

# load bytebeat
./getbb.py

# complile code
gcc -std=c2x -o t thing.c func.c func.h 2> errordata.txt
gcc -std=c2x -o b bitwcomp.c func.c func.h

# run code
if [`cat errordata.txt` = ""]
then
    ./t
    ./b
else
    echo "Bytebeat is not C-compatible!"
    rm t && rm b
    exit 1
fi

# delete executables
rm t && rm b && rm errordata.txt
read -p ""
clear
