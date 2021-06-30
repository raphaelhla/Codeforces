def dfs(v):
	if v == -1:
		return 1
	return 1 + dfs(dic[v])
	
t = int(input())

dic = {}
for tt in range(1,t+1):
	p = int(input())
	dic[tt] = p
	
resp = 0
for i in range(1,t+1):
	resp = max(resp, dfs(i))
	
print(resp)
