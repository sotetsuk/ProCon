n, v = [int(x) for x in raw_input().split()]

p = []
k = []

for _ in range(n):
    a = [int(x) for x in raw_input().split()]
    p.append(a[0])
    k.append(a[1:])

c = 0
ret = ""
for i in range(n):
    for b in k[i]:
        if b < v:
            c += 1
            ret += str(i+1) + " "
            break

print c
print ret
