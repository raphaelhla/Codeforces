def resp(n):
	
	if n < 4:
		return n -1
	else:	
		if n % 2 == 0:
			return 2
		else:
			return 3


t = int(input())

for tt in range(t):
	
	n = int(input())	
	print(resp(n))

