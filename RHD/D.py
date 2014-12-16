M = int(raw_input())
X = [int(x) for x in raw_input().split()]

for i in range(M):
    Y = [int(x) for x in X]
    if i == 0:
        pass
    if i == M - 1:
        pass
    else:
        for j in range(i):
            if j == -1:
