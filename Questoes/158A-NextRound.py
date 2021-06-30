n, k = input().split()
k = int(k)

lista = [int(x) for x in input().split()]

cont = 0

for i in range(len(lista)):
	if lista[i] > 0 and lista[i] >= lista[k-1]:
		cont += 1
		
print(cont)
