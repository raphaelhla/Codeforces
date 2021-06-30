t = int(input())
 
for tt in range(t):
	n = int(input())
	s = list(input())
	
	s.sort()
	
	resp = ""
	
	for e in s:
		resp += e
	
	print(resp)