k, n, w = [int(x) for x in input().split()]

preco = 0

for i in range(w):
    preco += (i+1)*k

fim = n - preco

if fim >= 0:
    print(0)
else:
    print(abs(fim))
