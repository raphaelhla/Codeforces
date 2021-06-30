n, t = [int(x) for x in input().split()]
fila = input()

lista = []

for e in fila:
    lista.append(e)

while t>0:
    trocou = False
    for i in range(len(lista)-2,-1,-1):
        if trocou:
            trocou = False
            continue
        if lista[i] == "B" and lista[i+1] == "G":
            lista[i], lista[i+1] = lista[i+1], lista[i]
            trocou = True
    t -= 1

print("".join(lista))


