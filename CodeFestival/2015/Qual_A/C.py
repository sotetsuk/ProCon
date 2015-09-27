N, T = [int(x) for x in raw_input().split()]
A = []
B = []
diff = []

for i in range(N):
    a, b = [int(x) for x in raw_input().split()]
    A.append(a)
    B.append(b)
    diff.append((a - b, i))

diff.sort(reverse=True)

S = sum(A)
c = 0
for a, b, d in zip(A, B, diff):
    if S <= T:
        break
    else:
        S -= d[0]
        c += 1

ans = c if S <= T else -1
print ans