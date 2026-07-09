#!/bin/bash

clear
rm in.txt && rm config.txt
touch in.txt && touch config.txt
echo -e "$1\n$2\n32" >> config.txt
chmod -R 777 ./
