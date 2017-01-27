#!/usr/bin/python3
import fileinput

waves = []
tests = -1
for line in fileinput.input():
	if(line == "0\n" or line == "0"):
		break
	elif(tests == -1):
		tests = int(line)
	else:
		waves = [int(i) for i in line.split(" ")]
		peaks = 0
		for i in range(0,len(waves)):
			if(i == 0):
				if(((waves[i] > waves[-1]) and (waves[i] > waves[1])) or ((waves[i] < waves[-1]) and (waves[i] < waves[1]))):
					peaks+=1
			elif(i == len(waves)-1):
				if((waves[i] > waves[i -1] and waves[i] > waves[0]) or (waves[i] < waves[i -1] and waves[i] < waves[0])):
					peaks+=1
			else:
				if((waves[i] > waves[i -1] and waves[i] > waves[i +1]) or (waves[i] < waves[i -1] and waves[i] < waves[i +1])):
					peaks+=1
		print(peaks)
		tests = -1
		waves = []


