# WA

N, M = [int(x) for x in raw_input().split()]
X = [int(raw_input()) for _ in range(M)]



def solve(N, M, X):
    t = 0
    r = 0
    while True:
        for i in range(M):
            S = X[i] - t
            if S - r > 1:
                r = 0
                break
            l = min(r + 1, X[i])
            r = max(X[i], (l + (t - (X[i] - l))))

            if r >= N:
                return t
        t += 1

ans = solve(N, M, X)
X_ = X[::-1]
for i in range(M):
    X[i] = N - X_[i]
ans = min(ans, solve(N, M, X))
print ans
