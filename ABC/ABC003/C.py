N, K = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]
arr.sort()
ans = 0
for i in arr[-K:]:
    ans = (ans + i) / 2
print(ans)
