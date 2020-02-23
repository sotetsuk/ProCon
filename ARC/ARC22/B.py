from collections import deque

N = int(raw_input())
A = [int(x) for x in raw_input().split()]

l = 0
r = 0

d = deque()
count = 0
while l < N:
    if r >= N:
        break
    if A[r] not in d:
        d.append(A[r])
        r += 1
        count = max(count, len(d))
    else:
        l += 1
        d.popleft()

print count
