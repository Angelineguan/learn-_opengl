import math

a=math.sin(60)

print(a)

vecNum=[1,2,3,4]
vecNum.append(12)
def sum(*vect):
	sum=0
	for x in vect:
		sum+=x

	return sum

print("the result of sum is",sum(*vecNum))

vecNum2=(1,22,3,4)

print(sum(*vecNum2))