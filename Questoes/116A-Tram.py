n = int(input())

maior = 0

passa = 0

for e in range(n):
    a, b = [int(x) for x in input().split()]
    
    passa -= a
    passa += b

    if passa > maior:
        maior = passa

print(maior)
