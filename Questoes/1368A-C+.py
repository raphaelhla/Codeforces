t = int(input())

for i in range(t):
	a, b, c = [int(x) for x in input().split()]
	cont = 0
	
	while (a <= c and b <= c):
		if a <= b:
			a += b
		elif b < a:
			b += a
		cont += 1
	print(cont)
