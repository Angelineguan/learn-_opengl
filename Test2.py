classmate=["lixinyu","guanyaqin","Liujunting"]
print(len(classmate))
for x in range(0,3):
	print(classmate[x])

print("")
for x in range(1,4):
	print(classmate[-x])

classmate.append("zhangna")
print(classmate[-1])

num=len(classmate)
print(num)	

print(classmate[0])
print("")
for x in range(0,num):
	print(classmate[x])

classmate.pop()
classmate.pop()
classmate.pop()
classmate.pop()

print(len(classmate))
classmate.insert(11,"asdas")
print(classmate[-1])

classmate[0]="guanyaqin"
print(classmate[-1])


