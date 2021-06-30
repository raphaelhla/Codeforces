a, b = [int(x) for x in input().split()]

resp = abs(a - b)

if resp <= 1 and (a > 0 or b > 0):
    print("YES")
else:
    print("NO")
