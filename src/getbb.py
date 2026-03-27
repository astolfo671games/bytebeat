#!/bin/python3

CODESTR: str = ";fwrite(&u, 1, 1, header);}\nputs(\"Bytebeat compiled successfully!\");\nreturn 0;}"
CODE1: str = "uint8_t u =\n"

from typing import TextIO

def getbb():
    bytebeat: str = open("../in.txt").read()
    f: TextIO = open("thing.c")
    lines: list[str] = f.readlines()
    while lines[-1] != CODE1:
        lines.pop()
    lines.append(bytebeat)
    f_w: TextIO = open("thing.c", "w+t")
    f_w.write(f"{"".join(lines)}\n{CODESTR}")

if __name__ == "__main__":
    getbb()
