y, w = [int(x) for x in input().split()]

maior = max(y, w)

prob = 6 - maior + 1
den = 6

if prob % 6 == 0:
    prob /= 6
    den /= 6
elif prob % 3 == 0:
    prob /= 3
    den /= 3
elif prob % 2 == 0:
    prob /= 2
    den /= 2

print("%d/%d"% (prob, den))

