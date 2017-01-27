#!/bin/usr/python3
# Answer for https://uva.onlinejudge.org/external/110/11062.pdf
# Author: Pedro Faustini
# Federal University of Rio Grande do Sul (UFRGS) - Brazil
# INF01056 - Programming Challenges
import fileinput
import re
# [a-z] is 97 - 112
# - is 45
hyphen = False
words = []
hyphenated=""

for line in fileinput.input():
	line = line.lower()
	line = line.split(" ")
	for word in line:
		if(len(word) >1 and word[-2] == '-' and not hyphen): # -2 because -1 would be \n
			
			hyphenated = word.replace("-","")
			hyphen = True
		elif(hyphen and word != '\n'):
			if(word[-2] != '-'): # hyphenation ends -> add word to dictionary
				hyphenated+=word
				hyphen = False
				hyphenated = hyphenated.replace("\n","")
				#print(hyphenated)
				# peer-2-peer and name@user and alike cases
				hyphenated = re.sub("([^qwertyuiopasdfghjklzxcvbnm-])", " ", hyphenated)
				hyphenated = hyphenated.split(" ")
				for w in hyphenated:
					if(w not in words and w != "" and w != " "):	
						words.append(w)
				hyphenated = ""
			else: # hyphenation in the middle of a word
				word = word.replace("-","")
				hyphenated+=word
				
		elif(word != '\n' and word != ""):
			word = word.replace("\n","")
			word = re.sub("([^qwertyuiopasdfghjklzxcvbnm-])", " ", word)
			word = word.split(" ")
			for w in word:
				if(w not in words and not w.isdigit() and w != ""):	
					words.append(w)
words.sort()
for word in words:
	print(word)			
			
