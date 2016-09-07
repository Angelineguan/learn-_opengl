
a={"a":"gyq","b":111,"c":"gyqqq"}
print(a["b"])

for x,y in a.items():
	print(x,y)

l=["GYQ","LIU12JUNTING","LIXINGYU"]

for x in l:
	y=x.lower()
	#$z=y.upper()
	print(y)
	#print(z)
	print(" ")

print(isinstance("123",str))

l=list(range(100000))

for x in l:
	print(x)