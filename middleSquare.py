import math

def middleSquare(n):
	if(n < 10):
		return 0

	l = math.floor(math.log10(n)) + 1
	chop = int(math.ceil(l/2.0))
	return (n*n//(10**chop)) % (10**(2*(l-chop)))

userinput = input("Enter a positive integer: ")
val = int(userinput)
print(middleSquare(val))
