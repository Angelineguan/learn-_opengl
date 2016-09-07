#l=[x*x for x in range(100)]
#print(l)

l=(x*x for x in range(1001100000000000001))
print(l)

for x in range(10000):
	print(next(l))