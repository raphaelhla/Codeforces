n = int(input())
ent = input()

a = 0
d = 0

for e in ent:
    if e == "A":
        a += 1
    else:
        d += 1

if a > d:
    print("Anton")
elif d > a:
    print("Danik")
elif d == a:
    print("Friendship")
