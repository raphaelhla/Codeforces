n = int(input())

for e in range(n):
	palavra = input()
	if len(palavra) > 10:
		palavra_nova = ""
		palavra_nova += palavra[0] + str(len(palavra) - 2) + palavra[len(palavra)-1]
		
		print(palavra_nova)
	else:
		print(palavra)
