entrada = int(input())


while True:
	entrada += 1
	boolean2 = False
	
	
	for e in range(len(str(entrada))):
		
		for k in range(len(str(entrada))):			
			if e != k and str(entrada)[e] == str(entrada)[k]:
				boolean2 = True
				
	if not boolean2:
		break
		
print(entrada)
