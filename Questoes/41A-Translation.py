a = input()
b = input()

lista = []

for e in a:
    lista.append(e)

lista.reverse()

if "".join(lista) == b:
    print('YES')
else:
    print('NO')
