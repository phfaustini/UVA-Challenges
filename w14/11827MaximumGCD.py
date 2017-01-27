#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2927
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges
from fileinput import input
from fractions import gcd

cases = None

for line in input():
    line = line.rstrip()
    if cases is None:
        cases = line
    else:
        numbers = [int(i) for i in line.split(" ")]
        i = 0
        l = len(numbers)
        max = 1
        for i in range(0, l-1):
            for j in range(i+1, l):
                n = gcd(numbers[i], numbers[j])
                if max < n:
                    max = n
        print(max)