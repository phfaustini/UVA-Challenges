#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1170
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges
from fileinput import input

fibonnaci_table = {}
fibonnaci_table[1] = 1
fibonnaci_table[2] = 1
for line in input():
    line = line.rstrip()
    line = [int(i) for i in line.split(" ")]
    print (line)
    if line[0] <= max(fibonnaci_table):
        print(fibonnaci_table[line[0]] % 2**line[1])
    else:
        pass