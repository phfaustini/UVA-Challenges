#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=484
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges
from fileinput import input

def prime(number):
    n = number - 1
    while n > 1:
        if(number % n == 0):
            return False
        n -= 1
    return True

for line in input():
    line = line.rstrip()
    if(not line.startswith("0")):
        number = int(line)
        n = number
        if n % 2 == 0:
            n+=1
            
        odd1 = n - 2
        while not prime(odd1) and odd1 > 1:
                odd1 -= 2 
        
        odd2 = odd1 - 2
        while not prime(odd2) and odd2 > 1:
                    odd2 -= 2

        while odd1 + odd2 > number:
            odd1 -=2
            while not prime(odd1) and odd1 > 1:
                odd1 -= 2 
            if odd1 <= 1:
                odd1 = n - 2
                while not prime(odd2) and odd2 > 1:
                    odd2 -= 2
        
        #2 in [Number,2**Number%Number]
        
        print(line+" = "+str(odd1)+" + "+str(odd2))
        