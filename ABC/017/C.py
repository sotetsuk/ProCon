N, M = [int(x) for x in raw_input().split()]
L = []
R = []
S = []
a = [[] for i in range(M)]

for i in range(N):
    l, r, s = [int(x) for x in raw_input().split()]
    l -= 1
    r -= 1
    L.append(l)
    R.append(r)
    S.append(s)

for i in range(N):
    for j in range(L[i], R[i] + 1):
        a[j].append(S[i])

ans = sum(S)
f = False

m = 100000
for j in range(M):
    m = min(sum(a[j]), m)

# print S
# print a
# print m

print ans - m
