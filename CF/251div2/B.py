n, x = [int(s) for s in raw_input().split()]
c = [int(s) for s in raw_input().split()]

c.sort()

ans = 0
for a in c:
    ans += x * a
    if x > 1:
        x -= 1

print(ans)
