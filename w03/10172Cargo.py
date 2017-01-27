#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/external/101/10172.pdf
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges

import fileinput
import sys

getSet = True
sets = 0
stations = 0
carrierCapacity = 0
platformCapacity = 0
header = False
carrier = [] # insert(index, number), pop(index)
time = 0
currentStation = 1
station = {}
for line in fileinput.input():
	if(getSet):
		sets = int(line)
		getSet = False
		header = True
	elif(header):
		header = False
		carrier = []
		time = 0
		currentStation = 0
		station.clear()
		line = line.split(" ")
		stations = int(line[0])
		carrierCapacity = int(line[1])
		platformCapacity = int(line[2])
	elif(stations > 0):
		currentStation+=1
		station[currentStation] = [int(i) for i in line.split(" ") if i != '\n']
		station[currentStation].pop(0) # Removes number of cargoes
		if(stations == currentStation):
			# Algorithm
			currentStation = 0
			while(True):
				currentStation+=1
				if(currentStation > stations):
					currentStation = 1
				queueB = station[currentStation]

				while(len(carrier) > 0):
					if(carrier[0] == currentStation):
						carrier.pop(0)
						time+=1
					elif(len(queueB) < platformCapacity):
						cargo = carrier.pop(0)
						queueB.append(cargo)
						time+=1
					else:
						break

				while(len(carrier) < carrierCapacity and len(queueB) > 0): # Loading
					carrier.insert(0,queueB.pop(0))
					time+=1

				if((sum(map(len, station.values())) == 0 and len(carrier) == 0)):
					break
				time+=2 # Moves to next station


			print(time)


			# Finishes or starts again with a new set
			sets-=1
			if(sets == 0):
				sys.exit(0)
			else:
				header = True
