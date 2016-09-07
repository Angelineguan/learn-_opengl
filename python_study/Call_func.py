
def myabs(x):
	if x>=0:
		return x
	else:
		return -x

def myfunction():
	pass

print("the abslute value of x is",myabs(-11))

print("test the function of person")

def person(name,age,**other):
	print("name",name,"age",age,"other",other)

print(person("guanyaqin","26",gender="男",job="IT"))
#dict test
kw={"gender":"男","job":"IT","salary":"200000"}
print(person("guanyaqin","26",**kw))

print(kw["gender"])
print(kw["job"])
kw["lovething"]="basketball"
print(person("guanyaqin","26",**kw))

kw.pop("job")

print(person("guanyaqin","26",**kw))


#递归函数的使用
print("递归函数的使用")

def fact(n):
	if n==1:
		return 1
	else:
		return n*fact(n-1)

print(fact(10))	


