n, d = [int(x) for x in input().split()]

lista = []
for nn in range(n):
	money, fator = [int(x) for x in input().split()]
	lista.append((money, fator))
	
lista.sort()
resp = 0
i = 0
j = 0
aux = 0

while j < n:
	if i == j:
		aux += lista[i][1]
		j += 1
	else:
		if lista[j][0] - lista[i][0] < d:
			aux += lista[j][1]
			j += 1
		
		else:
			resp = max(aux, resp)
			aux -= lista[i][1]
			i += 1
			
			
resp = max(aux, resp)		
	
	
print(resp)
