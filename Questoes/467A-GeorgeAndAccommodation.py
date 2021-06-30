n = int(input())

cont = 0

for e in range(n):
    p, q = [int(x) for x in input().split()]

    if q - p >= 2:
        cont += 1

print(cont)
