#!/usr/bin/python3
# Answer for https://uva.onlinejudge.org/external/109/p10954.pdf
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges
import fileinput
import sys
numbers = 0
sum = 0
for line in fileinput.input():
	if(len(line.split()) == 1 and numbers == 0): # At line that informs how many numbers'll be processed
		sum = 0
		if(int(line) == 0):	# End of file
			sys.exit(0)
		else:
			numbers = int(line) # Get number of numbers
	else:
		if(len(line.split()) == 1): # Only one element, no cost to sum
			print(0)
			numbers = 0
		else: # Process costs
			n = [int(i) for i in line.split()]
			n.sort()
			while(len(n) >= 2):
				temp=n.pop(0)+n.pop(0)
				sum+=temp
				n.append(temp)
				n.sort()
			print(sum)			
			numbers = 0
			
