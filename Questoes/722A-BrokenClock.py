def relogio(formato, hora):
	a = int(hora.split(":")[0])
	b = int(hora.split(":")[1])
	
	if formato == 12:
		if a > 12 and a % 10 != 0:
			a = a % 10
		elif (a > 12 or a < 1) and a % 10 == 0:
			a = (a % 10) + 10						
	else:
		if a > 23 and a % 10 != 0:
			a = a % 10
		elif a > 23 and a % 10 == 0:
			a = (a % 10) + 10		
	
	if b > 59 and b % 10 != 0:
		b = b % 10
	elif b > 59 and b % 10 == 0:
		b = (b % 10) + 10
		
	return("%02d:%02d" %(a,b))
 
 
formato = int(input())
hora = input()
print(relogio(formato, hora))
