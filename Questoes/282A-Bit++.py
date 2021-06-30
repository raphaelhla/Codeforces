n = int(input())

x= 0
for e in range(n):
	op = input()
	
	if op == "++X" or op == "X++":
		x += 1
	elif op == "--X" or op == "X--":
		x -= 1
		
print(x)
