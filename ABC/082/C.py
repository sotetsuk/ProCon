m = {}

N = int(input())
a = [int(x) for x in input().split()]

c = 0
for b in a:
    if b in m.keys():
        if m[b] >= b:
            c += 1
        else:
            m[b] += 1
    else:
        m[b] = 1

for k, v in m.items():
    if k > v:
        c += v

print(c)
