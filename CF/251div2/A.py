n, d = [int(x) for x in raw_input().split()]
t = [int(x) for x in raw_input().split()]

if sum(t) + (n-1) * 10 > d:
    print(-1)
else:
    print((n-1)*2 + (d - sum(t) - (n-1) * 10) / 5)
