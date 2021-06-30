n = input()
livrosL = input().split()
ordem = input().split()
 
livros = {}
resp = []
i = 0
cont = 0
 
for e in livrosL:
	livros[e] = 0
 
for j in livros:
	while livros[ordem[i]] == 1:
		resp.append(str(cont))
		i += 1
	
	cont += 1
	
	if j == ordem[i]:
		resp.append(str(cont))
		cont = 0
		i += 1
	else:
		livros[j] = 1
 
while len(resp) < len(livros):
	resp.append(str(cont))			
	
print(" ".join(resp))
