#coding=utf-8
import string
def xiangcheng(n,m):
    return n*m
use=input("enter 1 number")
es=input("hahahah")
we=xiangcheng(int(use),int(es))
print("%d"%we)
#second try
use=input("please input your scores:")
us=int(use)
if us>90:
    print("A")
elif us>80:
    print("B")
else:
    print("C")
for eachnum in range(10):
    print ("%d" % eachnum)
