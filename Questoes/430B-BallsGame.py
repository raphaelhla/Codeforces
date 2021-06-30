n, k, bola = [int(x) for x in input().split()]
fila = [int(x) for x in input().split()]
 
removidas = 0
 
for i in range(n):
	copia = fila.copy()
	copia.insert(i, bola)
	while len(copia) > 2:
		tmp = len(copia)
		for j in range(len(copia)-2):
			if copia[j] == copia[j+1] == copia[j+2]:
				p = j + 3
				while p < len(copia):
					if copia[j] != copia[p]:
						break
					p += 1
				copia = copia[:j] + copia[p:]
				break
		if tmp == len(copia):
			break
	removidas = max(removidas, n - len(copia))
print(removidas)
