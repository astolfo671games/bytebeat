#!/bin/python3

CODE1: str = "uint8_t u =\n"

from typing import TextIO

# import bytebeat code into thing.c
def getbb():
    bytebeat: str = open("../in.txt").read()
    f_r: TextIO = open("thing.c", "rt")
    lines: list[str] = f_r.readlines()
    final_lines: list[str] = []

    while lines[-1] != CODE1:
        final_lines.append(lines.pop())
    lines.append(bytebeat)
    final_lines = "".join(list(reversed(final_lines[:-1])))

    f_w: TextIO = open("thing.c", "w+t")
    thing_c: str = "".join(lines)
    f_w.write(f"{thing_c}\n{final_lines}")

if __name__ == "__main__":
    getbb()
