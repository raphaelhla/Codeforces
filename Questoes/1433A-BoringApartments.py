t = int(input())
 
for tt in range(t):
	x = input()
	resp = (int(x[0]) - 1) * 10
	
	for i in range(len(x), 0, -1):
		resp += i
		
	print(resp)
