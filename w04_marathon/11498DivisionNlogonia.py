#!/usr/bin/python3

import fileinput
queries = -1
nCoord = -1
mCoord = -1
counter = 1
for line in fileinput.input():
	if(line == "0\n" or line == "0"):
		break
	elif(queries == -1):
		queries = int(line)
	elif(nCoord == -1):
		line = line.split(" ")
		nCoord = int(line[0])
		mCoord = int(line[1])
	else:
		line = line.split(" ")
		line[0] = int(line[0])
		line[1] = int(line[1])
		if(line[0] > nCoord and line[1] > mCoord):
			print("NE")
		elif(line[0] > nCoord and line[1] < mCoord):
			print("SE")
		elif(line[0] < nCoord and line[1] < mCoord):
			print("SO")
		elif(line[0] < nCoord and line[1] > mCoord):
			print("NO")
		else:
			print("divisa")
		counter+=1
		if(counter > queries):
			counter = 1
			queries = -1
			nCoord = -1
			mCoord = -1
		
