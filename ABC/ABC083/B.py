n, a, b = [int(x) for x in input().split()]

ans = 0
for x in range(n + 1):
    s = sum([int(c) for c in str(x)])
    if a <= s <= b:
        ans += x

print(ans)
