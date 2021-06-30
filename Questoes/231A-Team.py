n = int(input())

cont = 0

for e in range(n):
	p, v, t = [int(x) for x in input().split()]
	
	if (p + v + t > 1):
		cont += 1
print(cont)
