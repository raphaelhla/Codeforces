n, k = [int(x) for x in input().split()]
idt = input().split()

soma = 1
i = 0

while soma <= k:
	i += 1
	soma += i

aux = k - (soma - i)
print(idt[aux])

