
#score=input("please input the score you have got: ")
score=14
if score>90:
	print("you are excellent")

elif score>=70 and score<=90:
	print("you are well")

else:
	print("you need work hard")	

names=["guanyaqin","lixinyu","liujunting"]
for name in names:
	print("the name is 12",name)
sum=0
for x in range(1000):
	sum+=x
print("the total is ",sum)	

l=list(range(1000))
sum=0
for x in l:
	sum+=l[x]
print("the total list sum is ",sum)

n=1000
sum1=0
while n>0:
	sum1+=n
	n-=1;
print(sum1)	

