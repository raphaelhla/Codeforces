n = int(input())
array = [int(x) for x in input().split()]

arraySort = array.copy()
arraySort.sort()
l, r = 0, 0

for i in range(n-1):
	if array[i] > array[i+1]:
		l = i
		break		
for i in range(n-1, 0, -1):
	if array[i] < array[i-1]:
		r = i
		break

aux = []
for i in range(r, l-1,-1):
	aux.append(array[i])

if aux == arraySort[l:r+1]:
	print("yes")	
	print("%d %d" % (l+1, r+1))
else:
	print("no") 
