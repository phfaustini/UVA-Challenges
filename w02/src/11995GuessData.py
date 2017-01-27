#!/usr/bin/python3
# Answer for https://uva.onlinejudge.org/external/119/11995.pdf
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges
import fileinput
getTestsAmout = True
tests=0
elements = []
structures = {}
structures['queue'] = 1
structures['priority queue'] = 1
structures['stack'] = 1
palindrome = []

for line in fileinput.input():
	if (getTestsAmout):
		getTestsAmout=False
		if(line != "\n"):
			tests = int(line)
			if(tests == 0):
				print("not sure")
				getTestsAmout = True
	else:
		line = [int(i) for i in line.split(" ") if i != '\n']
		if(line[0] == 1):
			elements.append(int(line[1]))

		else:
			#print(line)
			n = int(line[1])
			palindrome.append(n)
			# Which structure it is?
			if(len(elements) > 1):
				if(n == elements[0] and (n != elements[-1])):
					structures['stack'] = 0
				if(n < max(elements)):
					structures['priority queue'] = 0
				if(n == max(elements) and n != elements[0] and n != elements[-1]):
					structures['stack'] = 0
					structures['queue'] = 0
				if(n == max(elements) and n == elements[0] and n != elements[-1]):
					structures['stack'] = 0
				if(n == max(elements) and n != elements[0] and n == elements[-1]):
					structures['queue'] = 0
				if((n == elements[-1]) and (n != elements[0])):
					structures['queue'] = 0
				if(n != elements[0] and n!=elements[-1] and n != max(elements)):
					structures['stack'] = 0
					structures['queue'] = 0
					structures['priority queue'] = 0


				# Decides who's going to be deleted
				if(structures['queue'] == 1 and structures['stack'] == 0):
					elements.pop(0)
				elif (structures['queue'] == 0 and structures['stack'] == 1):
					elements.pop(-1)
				else:
					if n in elements:
						elements.remove(n)
					else:
						structures['stack'] = 0
						structures['queue'] = 0
						structures['priority queue'] = 0

			elif(len(elements) == 1):
				elements.pop(0)




		tests-=1
		if(tests <= 0): # Print result and reinitialise data
			total = 0
			key = ""
			for k,v in structures.items():
				if(v == 1):
					key = k
					total+=1
			if(total > 1):
				print("not sure")
			elif(total == 0):
				print("impossible")
			else:
				if(palindrome == palindrome[::-1] and key == "queue"):
					print("not sure")
				else:
					print(key)
			getTestsAmout = True
			elements = []
			palindrome = []
			structures = {}
			structures['queue'] = 1
			structures['priority queue'] = 1
			structures['stack'] = 1
