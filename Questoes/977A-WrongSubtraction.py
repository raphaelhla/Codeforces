n, k = [int(x) for x in input().split()]

for e in range(k):
    if n % 10 == 0:
        n //= 10
    else:
        n -= 1

print(n)
