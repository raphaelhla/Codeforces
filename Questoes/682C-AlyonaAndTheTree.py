from collections import deque
 
n = int(raw_input())
valores = [0] + [int(x) for x in raw_input().split()]
g = [[] for _ in range(n+1)]
distancia = [0] * (n+1)
 
for e in range(2, n+1):
	p, c = [int(x) for x in raw_input().split()]
	g[p].append((e, c))
	
resp = 0
retira = [False] * (n+1)
pilha = deque([1])
while pilha:
	v = pilha.pop()
	if retira[v]:
		resp += 1
	for u, d in g[v]:
		distancia[u] = max(d, distancia[v]+d)
		if distancia[u] > valores[u]:
			retira[u] = True
		else:
			retira[u] = retira[v]
		pilha.append(u)
 
print(resp)
