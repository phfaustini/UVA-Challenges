#!/usr/bin/python3

from fileinput import input

lines = -1
text = ""
letters = {}
for line in input():
	if(lines == -1):
		lines = int(line)
	else:
		text += line

for w in text:
	w = w.upper()
	if(w.isalpha()):
		if(w not in letters and w.isalpha()):
			letters[w] = 1
		else:
			letters[w] += 1

a = sorted(letters.items(), key=lambda x: (-x[1], x[0]))

for w in a:
	print(w[0],w[1])
