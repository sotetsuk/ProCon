import math

N = int(raw_input())
A = [int(x) for x in raw_input().split()]

s = 0
c = 0
for a in A:
    if a:
        s += a
        c += 1

print int(math.ceil(1. * s / c))
