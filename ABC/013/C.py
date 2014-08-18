import math

n, h = [int(x) for x in raw_input().split()]
a, b, c, d, e = [int(x) for x in raw_input().split()]

m = []
for x in range(n+1):
    y = (1.*(n-x)*e-h-b*x)/(d+e)
    print y
    if int(y) == y:
        y = int(y) + 1
    else:
        y = int(math.ceil(y))
    if y >= 0:
        print x, y, x*a+y*c
        m.append(x * a + y * c)
print min(m)
