N = int(raw_input())

ans = []

s = 0
for i in range(1, 10):
    for j in range(1, 10):
        s += i*j

for i in range(1, 10):
    for j in range(1, 10):
        if i * j == s - N:
            ans.append((i, j))

for i, j in ans:
    print str(i) + " x " + str(j)
