n = input()
ent = input()

lista = []

for e in ent:
	lista.append(e)
cont = 0
for i in range(len(lista)-1, 0, -1):
	 if lista[i] == lista[i-1]:
		 cont+= 1
	 
print(cont)
