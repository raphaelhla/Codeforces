import sys
sys.setrecursionlimit(10**5)
n, m = [int(x) for x in input().split()]
tudo = []
g = []
cor = []
 
ciclo = ["No"]
 
for e in range(n):
	entrada = input()
	tudo.append(entrada)
	g.append([[]] * m)
	cor.append([False] * m)
 
 
def gera_lista_adjacencia():
	for i in range(n):
		for j in range(m):
			aux = []
	
			if i and tudo[i][j] == tudo[i-1][j]:
				aux.append((i-1,j))
			if j and tudo[i][j] == tudo[i][j-1]:
				aux.append((i,j-1))
			if i+1 < n and tudo[i][j] == tudo[i+1][j]:
				aux.append((i+1,j))
			if j+1 < m and tudo[i][j] == tudo[i][j+1]:
				aux.append((i,j+1))
			g[i][j] = aux
 
 
def dfs(anterior, i, j):
	cor[i][j] = True
	
	for e in g[i][j]:
		if e == anterior: continue
		if cor[e[0]][e[1]]:
			ciclo[0] = "Yes"		
		elif not cor[e[0]][e[1]]:
			dfs((i, j), e[0], e[1])	
	
gera_lista_adjacencia()
for i in range(n):
	for j in range(m):
		if not cor[i][j]:
			dfs((-1,-1), i, j)
					
 
print(ciclo[0])
