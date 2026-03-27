#!/bin/bash

clear
rm in.txt && rm config.txt
touch in.txt && touch config.txt
echo -e "44100\n1000000\n32" >> config.txt
chmod 777 ./in.txt && chmod 777 ./config.txt
