palavra = input()

maiuscula = 0
minuscula = 0

for e in palavra:
    if e.islower():
        minuscula += 1
    else:
        maiuscula += 1

if maiuscula > minuscula:
    print(palavra.upper())
elif minuscula >= maiuscula:
    print(palavra.lower())

