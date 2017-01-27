#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1346
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges
from fileinput import input

def sequence(l0,l1):
    l0.insert(0,"")
    l1.insert(0,"")
    m = len(l0)
    n = len(l1)
    matrix = {}
    maximum = 0
    for i in range(0,m):
        matrix[i] = [0] * n
    for i in range(1,m):
        for j in range(1,n):
            if(l0[i] == l1[j]):
                matrix[i][j] = matrix[i-1][j-1] + 1
            else:
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1])
            if(matrix[i][j] > maximum):
                maximum = matrix[i][j]
    return(maximum)


s0 = ""
s1 = ""
turn = 0
for line in input():
    if(turn == 0):
        s0 = [i for i in line.rstrip()]
        turn = 1
    else:
        turn = 0
        s1 = [i for i in line.rstrip()]
        print(sequence(s0,s1))
