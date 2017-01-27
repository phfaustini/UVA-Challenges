#!/usr/bin/python3
# Answer for https://uva.onlinejudge.org/external/112/11286.pdf
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges
import sys
import fileinput

lineNumber = 0
frosh = 0
combinations = {}
courses = []
for line in fileinput.input():
	if(lineNumber == 0):
		combinations={}
		courses=[]
		frosh = int(line)
		if(frosh == 0):
			sys.exit(0)
		else:
			lineNumber = 1
	else:
		 courses = [int(i) for i in line.split(" ") if i != '\n']
		 courses.sort()
		 num = int(''.join(map(str,courses)))
		 if(num in combinations):
		 	combinations[num]+=1
		 else:
		 	combinations[num]=1
		 if(lineNumber == frosh):
		 	lineNumber = 0
		 	biggest = 0
		 	mostPopular = 0
		 	for k,i in combinations.items():
		 		if i == biggest:
		 			biggest = i
		 			mostPopular+=1
		 		elif i > biggest:
		 			biggest = i
		 			mostPopular=1
		 	if(biggest == 1):
		 		print(frosh)
		 	else:
		 		print(biggest*mostPopular)	
		 else:
		 	lineNumber+=1

