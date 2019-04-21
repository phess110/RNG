def algorithmK(X):
	Y = X//1000000000
	while(Y >= 0):
		Z = (X//100000000) % 10
		if(Z <= 0):
			if(X < 5000000000):
				X += 5000000000
		if(Z <= 1):
			X = ((X**2//100000) % 10000000000)
		if(Z <= 2):
			X = (1001001001 * X % 10000000000)
		if(Z <= 3):
			if(X < 100000000):
				X += 9814055677
			else:
				X = 10000000000 - X
		if(Z <= 4):
			X = 100000 * (X % 100000) + X//100000
		if(Z <= 5):
			X = (1001001001 * X % 10000000000)
		if(Z <= 6):
			sub = 0
			multiplier = 1
			temp = X
			while( temp > 0 ):
				sub += multiplier if temp % 10 != 0 else 0
				temp //= 10
				multiplier *= 10
			X -= sub
		if(Z <= 7):
			if(X < 100000):
				X = X**2 + 99999
			else:
				X -= 99999
		if(Z <= 8):
			while(X < 1000000000):
				X *= 10
		X = (X*(X-1)//100000) % 10000000000
		Y -= 1
	return X

print(algorithmK(6065038420)) # stationary point of K(x)

# Rapidly falls into a cycle 
x = 3830951656
for i in range(10):
	print(x)
	x = algorithmK(x)
