N, H = [int(x) for x in raw_input().split()]
A, B, C, D, E = [int(x) for x in raw_input().split()]

m = 1e25
for x in range(N + 1):
    for y in range(N + 1):
        if H + B * x + D * y > (N - x - y) * E:
            m = min(A * x + C * y, m)

print int(m)
