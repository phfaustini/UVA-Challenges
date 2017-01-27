#!/usr/bin/python
from fileinput import input

words  = -1

for line in input():
	line = line.rstrip()
	if (words == -1):
		words = int(line)
	else:
		words -= 1
		word = line
		if(len(word) > 3):
			print(3)
		else:
			if(line.startswith("on")):
				print(1)
			elif(line.startswith("tw")):
				print(2)
			elif(line.endswith("ne")):
				print(1)
			elif(line.endswith("wo")):
				print(2)
			elif(line.startswith("o") and line.endswith("e")):
				print(1)
			else:
				print(2)
		if(words == 0):
			words = -1
