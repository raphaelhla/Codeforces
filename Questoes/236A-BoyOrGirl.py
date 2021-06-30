ent = input()

lista = []

for e in ent:
    if e not in lista:
        lista.append(e)

if len(lista) % 2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
