n, k = [int(x) for x in raw_input().split()]

s = 0
for i in range(n):
    s += int(raw_input())
    if s >= k:
        print i + 1
        break
