a = int(input())

for e in range(a):
	n, m = [int(x) for x in input().split()]
	if (n== 1 or m == 1) or (n == 2 and m ==2):
		print("YES")
	else:
		print("NO")
