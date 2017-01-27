#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=10&page=show_problem&problem=762
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges
from fileinput import input

graph = {}
test = 0

for line in input():
	line = line.rstrip()
	if(line.startswith("0 0")):
		break
	else:
		test += 1
		line = line.split(" ")
		while '' in line: line.remove('')
		line = [int(i) for i in line]
		nodes = len(set(line)) - 1
		unique = [i for i in set(line)]
		unique.sort()
		unique.remove(0)
		
		# Building graph
		for i in range(0, nodes):
			graph[ unique[i] ] = [101]*nodes
		for i in range(0, len(line)-2,2): # excludes last two zeroes
			graph[ line[i] ][ unique.index( line[i+1] ) ] = 1
				
		# Beginnig Floyd's algorithm
		for k in range(0, nodes):
			for i in range(0, nodes):
				for j in range(0, nodes):
					graph[ unique[i] ][j] = min(graph[ unique[i] ][j], graph[ unique[i] ][k] + graph[ unique[k] ][j])
		# Ending Floyd's algorithm
				
		# Some adaptions to the graph
		for i in range(0, nodes):
			for j in range(0, nodes):
				if( unique[i] == unique[j] ):
					graph[unique[i]][j] = 0
					
		# Calculating length
		clicks = 0
		for k,v in graph.items():
			for i in v:
				if(i != 101):
					clicks += i
		clicks /= (nodes**2 - nodes)

		print("Case "+str(test)+": average length between pages = %.3f clicks"% (clicks))
		graph.clear()
