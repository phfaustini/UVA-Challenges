#!/usr/bin/python3
from fileinput import input

tasks = -1
edges = -1
graph = {}
precedence = []
nodes = []
for line in input():
	line = line.rstrip()
	line = line.split(" ")
	if(tasks == -1):
		if(line[0] == line[1] == "0"):
			from sys import exit
			exit(0)
		elif(line[1] == "0"):
			tasks = int(line[0])
			for p in range(1,tasks+1):
				print(p,end="")
				print(" ",end="")
			print("")
			tasks = -1
			edges = -1
		else:
			tasks = int(line[0])
			edges = int(line[1])
			for t in range(1,tasks+1):
				graph[t] = []
				nodes.append(t)
	else:
		edges -=1
		graph[int(line[0])].append(int(line[1]))

		if(edges == 0):
			while(len(nodes) > 0):
				temp = None
				for n in nodes:
					remove = True
					for k,v in graph.items():
						if(n in v):
							remove = False
					if(remove):
						temp = n
						break
				precedence.append(temp)
				graph.pop(temp)
				nodes.remove(temp)

			for p in precedence:
				print(p,end="")
				print(" ",end="")
			print("")

			tasks = -1
			edges = -1		
			graph.clear()
			precedence = []
