from itertools import permutations

N = int(raw_input())
C = [int(raw_input()) for _ in range(N)]

s = 0
for c in permutations(C):
    b = [1] * len(C)
    for i in range(len(C)):
        for j in range(i+1, len(C)):
            if c[j] % c[i] == 0:
                b[j] = 1 if b[j] == 0 else 0
    s += sum(b)

def fanctional(n):
    if n == 1:
        return 1
    return n * fanctional(n-1)

print 1.*s/fanctional(N)
