fib = []
fib.append(1)
fib.append(2)

for i in range(2, 110):
	fib.append(fib[i - 1] + fib[i - 2])

first = True

while True:
	try:
		if not first:
			input()
			
		a = input()
		b = input()
		
		num1 = 0
		for i in range(0, len(a)):
			if a[i] == '1':
				num1 += fib[len(a) - 1 - i]
		num2 = 0
		for i in range(0, len(b)):
			if b[i] == '1':
				num2 += fib[len(b) - 1 - i]
		
		resp = []
		soma = num1 + num2
		cnt = -1
		
		while soma:
			l = 0
			r = 105
			
			while l != r:
				mid = (l + r) // 2
				if fib[mid] <= soma:
					l = mid + 1
				else:
					r = mid
			l -= 1
			
			resp.append(l)
			soma -= fib[l]
			cnt += 1
		
		aux = ""
		
		if not first:
			print()
		
		if cnt == -1:
			print(0)
		else:
			for i in range(0, 101):
				if cnt < 0:
					break
				
				if resp[cnt] == i:
					aux += '1'
					cnt -= 1
				else:
					aux += '0'

			print(aux[::-1])
		
		first = False
		
	except EOFError:
		break
