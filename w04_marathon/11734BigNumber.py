#!/usr/bin/python3
import fileinput

case = 0
start = True
team = ""
for line in fileinput.input():
	if(start):
		start = False
	else:
		if(team == ""):
			team = line
		else:
			case+=1
			if (line == team):
				print("Case "+str(case)+": Yes")
			elif(team.replace(" ","") == line):
				print("Case "+str(case)+": Output Format Error")
			else:
				print("Case "+str(case)+": Wrong Answer")			
			team = ""
		
