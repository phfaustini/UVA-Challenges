#!/usr/bin/python3

from fileinput import input

cases = None
c = 0
for line in input():
	line = line.rstrip()
	if cases is None:
		cases = int(line)
	elif cases > 0:
		cases -= 1
		c+=1
		line = [int(i) for i in line.split(" ")]
		current = line[1]
		for i in range(line[2]):
			current += 1
			if current > line[0]:
				current = 1
		print("Case "+str(c)+": "+str(current))
