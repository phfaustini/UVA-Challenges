#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1346
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges
from fileinput import input

def output(n, k):
    if( k < 2):
        return n;
    elif(k == 2):
        return n+1
    else:
        

for line in input():
    line = line.rstrip()
    line = [int(i) for i in line.split(" ")]
    if(sum(line) > 0):
        if(line[1] <= 1):
            print(1)
        elif(line[1] == 2):
            print(line[0] + 1)
        else:
            output(line[0],line[1])
