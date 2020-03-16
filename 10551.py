def convertbase(num, base):
	aux = chr(48 + (num % base))
	num //= base
	
	while num:
		aux +=  chr(48 + (num % base))
		num //= base
	return int(aux[::-1])
	
	
x = input()
while len(x) > 1 or x != '0':
	b, x, y = x.split()
	b = int(b)
	x = int(x, b)
	y = int(y, b)
	
	print(convertbase(x % y, b))
	x = input()
