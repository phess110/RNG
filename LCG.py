
class LCG:
	def __init__(self, X_0, a, c, m):
		self.X_0 = X_0
		self.a = a
		self.c = c
		self.m = m

	# Returns nth element in LCS 
	def getIdx(n):
		x = pow(self.a, n, self.m)
		b = pow(self.a - 1, -1, m)
		return (x * self.X_0 + (x - 1) * c * b) % m


class LCS:
	def __init__(self, LCG):
		self.LCG = LCG
		self.n = 0
		self.X_n = LCG.X_0

	# Returns next element in LCS
	def getNext(self):
		self.n += 1
		self.X_n = (LCG.a * self.X_n + LCG.c) % LCG.m
		return self.X_n



