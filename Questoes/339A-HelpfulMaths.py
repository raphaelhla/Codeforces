biu = [int(x) for x in input().split("+")]

biu.sort()

for i in range(len(biu)):
	biu[i] = str(biu[i])
print("+".join(biu))


