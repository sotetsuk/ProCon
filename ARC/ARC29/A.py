from itertools import combinations

N = int(raw_input())
t = [int(raw_input()) for _ in range(N)]

if N == 1:
    print t[0]
else:
    s1 = sum(t)
    ans = 1e9
    for i in range(1, N):
        for a in combinations(t, i):
            s2 = sum(a)
            ans = min(ans, max(s2, s1 - s2))

    print ans
