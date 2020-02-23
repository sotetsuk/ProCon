import math

N, H = [int(x) for x in raw_input().split()]
A, B, C, D, E = [int(x) for x in raw_input().split()]

m = 1e30
epsilon = 1e-10
for x in range(N + 1):
    t = 1. * ((N - x) * E - H - B * x) / (D + E)
    y = max(0, math.ceil(t + epsilon))
    m = min(A * x + C * y, m)

print int(m)
