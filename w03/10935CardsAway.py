#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/external/109/10935.pdf
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges

import fileinput

for line in fileinput.input():
	if(int(line) == 0):
		break
	else:
		n = int(line)
		deck = []
		discarded = []
		for i in range(1, n+1):
			deck.append(i)
		if(len(deck) == 1):
			print("Discarded cards:")
			print("Remaining card: "+str(deck[0]))
		else:
			while(len(deck)>2):
				discarded.append(deck.pop(0))
				temp = deck.pop(0)
				deck.append(temp)
			discarded.append(deck.pop(0))
			discarded = str(discarded).replace("[","")
			discarded = str(discarded).replace("]","")
			print("Discarded cards: "+str(discarded))
			print("Remaining card: "+str(deck[0]))
