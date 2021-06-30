qtd = input()
numeros = [int(x) for x in input().split()]
 
soma = 0
for e in numeros:
	soma += e
 
aux = 0
resposta = 0
for i in range(0, len(numeros)-1):
	aux += numeros[i]
	soma -= numeros[i]
	if aux == soma:
		resposta += 1
		
print(resposta)
