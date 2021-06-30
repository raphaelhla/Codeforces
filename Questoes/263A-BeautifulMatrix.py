def procura(matrix):
	a = 0
	b = 0
	ach = False
	for i in range(len(matrix)):
		for j in range(len(matrix[i])):
			if matrix[i][j] == "1":
				a = i
				b = j
				ach = True
				break
		if ach:
			break
	return [a,b]
	

l1 = input().split()
l2 = input().split()
l3 = input().split()
l4 = input().split()
l5 = input().split()

matrix = [l1, l2, l3, l4, l5]
cont = 0

resp = procura(matrix)
fin = abs(2 - resp[0]) + abs(2 - resp[1])
print(fin)

