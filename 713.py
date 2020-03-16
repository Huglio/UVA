def reversestring(var):
	aux = ""
	for i in range(len(var) - 1,-1,-1):
		aux += var[i]
	return str(aux)

tc = int(input())

while(tc):
	tc -= 1
	num1, num2 = input().split()
	num1 = reversestring(num1)
	num2 = reversestring(num2)
	
	num1 = int(num1)
	num2 = int(num2)
	result = int(reversestring(str(num1 + num2)))
	
	print("{}".format(result))
	
	
