while True:
	try:
		n, a = input().split()
		n = int(n)
		a = int(a)
		
		resp = 0
		for i in range(1, n + 1):
			resp += i * a ** i
		
		print("{}".format(resp))
	except EOFError:
		break
