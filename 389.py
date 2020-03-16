def convertbase(num, base):
	resp = ""
	
	if num % base <= 9:
		resp += chr(48 + (num % base))
	else:
		resp += chr(55 + (num % base))
	num //= base
	
	while num:
		if num % base <= 9:
			resp += chr(48 + (num % base))
		else:
			resp += chr(55 + (num % base))
		num //= base
	
	
	return resp[::-1]
		

while True:
	try:
		n, a, b = input().split()
		a = int(a)
		b = int(b)
		
		n = int(n, a)
				
		resp = convertbase(n, b)
		if len(resp) <= 7:
			print("%7s" % resp)
		else:
			print("%7s" % "ERROR")
		
		
	except EOFError:
		break
		
