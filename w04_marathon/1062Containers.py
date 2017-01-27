#!/usr/bin/python3
import fileinput

case = 0

for line in fileinput.input():
	if(line == "end" or line == "end\n"):
		break
	else:
		case+=1
		stacks=[[]]
		for ch in range(len(line)-1, -1, -1):
			inserted = False
			if(line[ch] == '\n'):
				pass
			else:
				for stack in stacks:
					if(len(stack) > 0):
						if(stack[-1] <= line[ch]):
							stack.append(line[ch])
							inserted = True
							break
					else:
						stack.append(line[ch])
						inserted = True
						break
				if(not inserted):
					stacks.append([line[ch]])


		print("Case "+str(case)+": "+str(len(stacks)))

