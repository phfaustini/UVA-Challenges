from fileinput import input

operations = -1

value = 0

for line in input():
	line = line.rstrip()
	if operations == -1:
		operations = int(line)
	elif line.startswith("donate"):
		line = line.split(" ")[1]
		value += int(line)
	elif line.startswith("repor"):
		print (value)

