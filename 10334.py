fib = []
fib.append(1)
fib.append(2)

for i in range(2, 1001):
	fib.append(fib[i - 1] + fib[i - 2])

while True:
	try:
		x = int(input())
		print(fib[x])
	
	except EOFError:
		break
