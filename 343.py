def minbase(num):
	aux = '0'
	for i in range(len(num) - 1, -1, -1):
		aux = max(aux, num[i])
	
	if aux >= 'A' and aux <= 'Z':
		return (10 + ord(aux) - ord('A')) + 1
	
	return int(aux) + 1

while True:
	try:
		a, b = input().split()
		
		ok = False
		for i in range(max(minbase(a), 2), 37):
			for j in range(max(minbase(b), 2), 37):
				if int(a, i) == int(b, j):
					ok = True
					break 
			if ok:
				break
		
		if ok:
			print("{} (base {}) = {} (base {})".format(a, i, b, j))
		else:
			print("{} is not equal to {} in any base 2..36".format(a, b))
			
	except EOFError:
		break
