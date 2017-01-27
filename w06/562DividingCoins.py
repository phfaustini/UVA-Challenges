#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=503
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges

from fileinput import input
begin = True
cases = -1
coins = -1
for line in input():
    if(begin):
        cases = int(line)
        begin = False
    elif(coins == -1):
        coins = 1
    else:
        coins = -1
        l2 = [int(i) for i in line.split(" ") if i != '\n']
        l2 = sorted(l2)
        half = sum(l2) / 2
        l1 = []
        difference = 0
        while(len(l2) > 0):
            l1.append(l2.pop(0))
            l1_sum = sum(l1)
            if( l1_sum == half):
                difference = 0
                break
            elif(l1_sum > half):
                difference = l1_sum - sum(l2)
                l1_len = len(l1)
                for i in range(0,l1_len):
                    l1_copy = l1[:]
                    l2_copy = l2[:]
                    for j in range(i, l1_len):
                        temp = l1_copy.pop(i)
                        l2_copy.append(temp)
                        sl1 = sum(l1_copy)
                        sl2 = sum(l2_copy)
                        diff2 = sl1 - sl2
                        if (diff2 < difference and diff2 >= 0):
                            difference = diff2
                        else:
                            break
                break
        print(difference)
