n = int(input())
amg = [int(x) for x in input().split()]

res = []

for e in range(n):
    res.append("")


for i in range(len(amg)):
    res[amg[i]-1] = str(i+1)

print(" ".join(res))

