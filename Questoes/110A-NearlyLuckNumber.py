n = input()

cont = 0
for e in n:
    if e == "7" or e == "4":
         cont += 1

if cont == 7 or cont == 4:
    print("YES")
else:
    print("NO")
