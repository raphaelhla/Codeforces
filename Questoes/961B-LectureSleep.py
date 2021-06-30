n, k = [int(x) for x in input().split()]
teoremas = [int(x) for x in input().split()]
acordado = [int(x) for x in input().split()]

acumuladoWake = [0] * (n+1)
acumuladoSleep = [0] * (n+1)

for i in range(1, n+1):
	acumuladoWake[i] = teoremas[i-1] + acumuladoWake[i-1]
	if acordado[i-1] == 1:
		acumuladoSleep[i] = teoremas[i-1] + acumuladoSleep[i-1]
	else:
		acumuladoSleep[i] = 0 + acumuladoSleep[i-1]

windowSum = 0
maxSum = 0

for i in range(1, n-k+2):
	wake = acumuladoWake[i+k-1] - acumuladoWake[i-1]
	sleep = acumuladoSleep[i+k-1] - acumuladoSleep[i-1]
	windowSum = wake - sleep
	
	maxSum = max(windowSum, maxSum)
print(maxSum+acumuladoSleep[n])
		
