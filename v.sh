#!/bin/bash

clear

# load bytebeat

./getbb.py

# complile code

gcc -std=c2x -o t thing.c func.c func.h
gcc -std=c2x -o b bitwcomp.c func.c func.h
./misc.py

# run code

if [$(cat temp) = ""]
then
    ./t
    ./b
else
    echo "Bytebeat is not C-compatible!"
    rm b && rm temp
    exit 1
fi

# delete executables

rm t && rm b && rm temp

read -p ""
clear
