def solve():
	n, k = [int(x) for x in input().split()]
	
	xs = []
	ys = []
	for nn in range(n):
		x, y = [int(x) for x in input().split()]
		xs.append(x)
		ys.append(y)
		
	resp = -1
	
	for i in range(n):
		entrou = False
		for j in range(n):
			if abs(xs[i] - xs[j]) + abs(ys[i] - ys[j]) > k:
				entrou = True
		
		if not entrou: 
			resp = 1
	
	return resp

t = int(input())
for tt in range(t):
	print(solve())
			
