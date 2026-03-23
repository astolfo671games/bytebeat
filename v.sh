#!/bin/bash

clear

# complile code

gcc -std=c2x -o t thing.c func.c func.h
gcc -std=c2x -o b bitwcomp.c func.c func.h

# run code

./t
./b

# delete executables

rm t && rm b

read -p ""
clear
