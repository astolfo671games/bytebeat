#!/bin/python3

from os import listdir
from typing import TextIO

def misc():
    temp: TextIO = open("temp", "w+t")
    if "t" not in listdir():
        temp.write(".")

if __name__ == "__main__":
    misc()
