#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=22&page=show_problem&problem=2001
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges

from fileinput import input

tests = True
test = 0
number_beverages = -1
number_relations = -1
graph = {}
precedence = []
beverages = []

# How many nodes, directly or indirectly,
# node 'node' reaches
def reachableBy(node, tempList):
    if(len(graph[node]) == 0):
        return
    else:
        for subNode in graph[node]:
            tempList[subNode] += 1
            reachableBy(subNode,tempList)

# Node 'node' is to be removed. Hence,
# decreases by 1 all nodes 'node' reaches
def substracts(node,tempList):
    if(len(graph[node]) == 0):
        return
    else:
        for subNode in graph[node]:
            tempList[subNode] -= 1
            substracts(subNode,tempList)


for line in input():
    line = line.rstrip()
    if(line == ""):
        pass
    elif(tests):
        tests = False
        test +=1
        number_beverages = int(line)
    elif(number_beverages > 0 and number_relations == -1):
        beverages.append(line)
        graph[line] = []
        number_beverages -= 1
    elif(number_relations == -1):
        number_relations = int(line)
        if(number_relations == 0):
            print("Case #"+str(test)+": Dilbert should drink beverages in this order:", end="")
            for b in beverages:
                print(" "+b, end="")
            print(".")
            print("")
            number_relations = -1
            number_beverages = -1
            graph = {}
            precedence = []
            beverages = []
            tests = True
    else:
        number_relations -= 1
        line = line.split(" ")
        graph[ line[0] ].append( line[1] )
        if(number_relations == 0):
            tempList = {}
            for b in beverages:
                tempList[b] = 0
            for b in beverages:
                reachableBy(b,tempList)

            while(len(beverages) > 0):
                from sys import maxsize
                min = maxsize
                element = None
                for b in beverages:
                    if(tempList[b] < min):
                        min = tempList[b]
                        element = b
                precedence.append(element)
                substracts(element,tempList)
                beverages.remove(element)

            print("Case #"+str(test)+": Dilbert should drink beverages in this order:", end="")
            for b in precedence:
                print(" "+b, end="")
            print(".")
            print("")

            number_relations = -1
            number_beverages = -1
            graph = {}
            precedence = []
            beverages = []
            tests = True
