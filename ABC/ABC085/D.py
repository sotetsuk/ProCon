n, h = [int(x) for x in input().split()]
a = []
b = []
for _ in range(n):
    x, y = [int(x) for x in input().split()]
    a.append(x)
    b.append(y)

l = list(zip(a, b))

a.sort()
b.sort(reverse=True)
p = a[-1]

c = 0
d = 0
for y in b:
    if y < p:
        break
    if d >= h:
        print(c)
        exit()
    c += 1
    d += y

if (h - d) % p == 0:
    c += ((h - d) // p)
else:
    c += ((h - d) // p + 1)
print(c)
