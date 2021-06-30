n = int(input())
 
cont = 0
 
x = []
y = []
visited = [0] * n
 
for e in range(n):
	ax, ay = [int(a) for a in input().split()]
	x.append(ax)
	y.append(ay)
 
def dfs(u):
	visited[u] = 1
	for i in range(n):
		if not visited[i] and (x[i] == x[u] or y[i] == y[u]):
			dfs(i)
 
for i in range(n):
	if not visited[i]:
		dfs(i)
		cont += 1
 
print(cont-1)
