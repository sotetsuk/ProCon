n = int(raw_input())
a = []
b = []
for _ in range(n):
    c, d = raw_input().split()
    a.append(int(c))
    b.append(int(d))

s = 0
for c, d in zip(a, b):
    if d - c >= 2:
        s += 1

print s
