N, x = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [0 for _ in range(N)]

A.sort()

ans = 0
for i in range(len(A)):
    if i == N - 1:
        B[i] = x
        break
    if x - A[i] >= 0:
        B[i] = A[i]
        x -= A[i]
    else:
        B[i] = 0
for i in range(len(A)):
    if A[i] == B[i]:
        ans += 1

print(ans)