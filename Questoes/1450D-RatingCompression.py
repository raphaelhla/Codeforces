t = int(input())

for tt in range(t):
	n = int(input())
	array = [int(x) for x in input().split()]
	cnt = [0] * (n+1)
	
	for e in array:
		cnt[e] += 1
	
	ans = []	
	flag = True
	l = 0
	r = n-1
	
	for i in range(1, n):
		if flag and cnt[i]:
			ans.append(1)
		else:
			ans.append(0)
		
		if cnt[i] != 1:
			flag = False
		elif array[l] == i:
			l += 1
		elif array[r] == i:
			r -= 1
		else:
			flag = False
	
	aux = set(array)
	if len(aux) == n:
		ans.append(1)
	else:
		ans.append(0)
	
	ans.reverse()
	for e in ans:
		print(e, end="")
	print()
