#!/usr/bin/python3
# Answer for https://uva.onlinejudge.org/external/115/11559.pdf
# Usage: python3 11559EventPlanning.py < file.txt
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges

import fileinput
lineNumber = 1
participants = 0
budget = 0
hotels = 0
weeks = 0
hotel = {}
pricePerson = 0
minPrices = []

def minimumCostStay(participants, budget):
	mininumCost = budget+1
	for place, beds in hotel.items(): # Iterate over hotels
		cost = int(beds[0])
		for bed in beds[1]:
			bed = int(bed)
			if bed >= participants and cost*participants <= budget:
				mininumCost = cost*participants
	if mininumCost <= budget:
		return mininumCost
	else:
		return -1


for line in fileinput.input():
	if lineNumber == 1:
		line = line.split(" ")
		participants = int(line[0])
		budget = int(line[1])
		hotels = int(line[2])
		weeks = int(line[3])
		lineNumber = 2
	elif lineNumber == 2:
		pricePerson = line
		lineNumber = 3
	elif lineNumber == 3:
		hotel["hotel"+str(hotels)] = (pricePerson,line.split())
		ap = minimumCostStay(participants, budget)
		if ap > -1:
			minPrices.append(ap)
		hotels-=1
		hotel = {}
		if(hotels == 0):
			lineNumber = 1
			if len(minPrices) == 0:
				print ("stay home")
			else:
				print (min(minPrices))
			minPrices = []
		else:
			lineNumber = 2
