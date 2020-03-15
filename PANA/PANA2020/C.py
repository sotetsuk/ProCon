from decimal import *

a, b, c = [int(x) for x in input().split(" ")]

A = Decimal(a)
B = Decimal(b)
C = Decimal(c)

if A.sqrt() + B.sqrt() < C.sqrt():
    print("Yes")
else:
    print("No")
