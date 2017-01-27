#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1193
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges

from fileinput import input

first = -1
second = -1
setFirst = {}
setSecond = {}

for line in input():
	line = line.rstrip()
	if first == -1:
		first = line
		for l in first:
			if l not in setFirst:
				setFirst[l] = 1
			else:
				setFirst[l] += 1
	else:
		second = line
		for l in second:
			if l not in setSecond:
				setSecond[l] = 1
			else:
				setSecond[l] += 1
		
		output = ""
		for kF, vF in setFirst.items():
			while True:
				if kF not in setSecond:
					break
				else:
					output+=str(kF)
					setFirst[kF] -= 1
					setSecond[kF] -= 1
					if setFirst[kF] == 0 or setSecond[kF] == 0:
						break

		output = (sorted(output))
		for l in output:
			print(l, end="")
		print("")

		first = -1
		second = -1
		setFirst.clear()
		setSecond.clear()
