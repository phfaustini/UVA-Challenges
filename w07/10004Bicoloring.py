#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=945
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges

edges = -1
nodes = -1
graph = {}
colours = {}

def printNeighbours(node, nodeColour, neighboursColour):
	global nodes
	if(nodes == 0):
		return
	if(colours[node] != neighboursColour):
		colours[node] = nodeColour
		nodes -= 1
		for n in graph[node]:
			printNeighbours(n, neighboursColour, nodeColour)


from fileinput import input
for line in input():
		line = line.split(" ")
		if(len(line) == 1 and nodes == -1):
			nodes = int(line[0])
			if(nodes == 0):
				break
			graph.clear()
			for n in range(0,nodes):
				graph[n] = []
				colours[n] = 0
		elif(len(line) == 1 and edges == -1):
			edges = int(line[0])
			if(edges == 0):
				print("BICOLORABLE.")
				edges = -1
				nodes = -1
		else:
			edges -= 1
			t1 = int(line[0])
			t2 = int(line[1])
			e1 = min(t1,t2)
			e2 = max(t1,t2)
			graph[e1].append(e2)

			if(edges == 0):
				printNeighbours(0,1,2)
				s = "BICOLORABLE."

				# Check whether all neighbours of a node have a different colour
				for k,v in graph.items():
					for n in v:
						if (colours[n] == colours[k] and n != k):
							s = "NOT BICOLORABLE."
				print(s)

				# Reinitialise variables and structures
				edges = -1
				nodes = -1
				graph.clear()
				colours.clear()
