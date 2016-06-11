n, X = [int(x) for x in raw_input().split()]
a = [int(x) for x in raw_input().split()]

X = bin(X)[2:]
s = 0
for i, c in enumerate(X[::-1]):
    if c == '1':
        s += a[i]

print s
