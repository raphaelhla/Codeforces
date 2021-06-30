n, m = [int(x) for x in input().split()]

lista = []
if n % m == 0:
	for e in range(m):
		lista.append(str(n//m))	
else:
	biu = (n//m) + 1
	ir = biu * m
	aux = ir - n
	for e in range(m):
		if e + 1 <= aux:
			lista.append(str(biu-1))
		else:
			lista.append(str(biu))
		
				
print(" ".join(lista))
