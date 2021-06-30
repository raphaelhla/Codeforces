t = int(input())

for tt in range(t):
	x, y, k = map(int, input().split())
	
	cont = 0
	precisa = (k * y + k) - 1	
	lucroPorTroca = x-1
	
	if precisa % lucroPorTroca == 0:
		cont = precisa // lucroPorTroca
	else:
		cont = (precisa // lucroPorTroca) + 1
	
	cont += k
	print(cont)
