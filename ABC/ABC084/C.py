import math

N = int(input())
c = []
s = []
f = []
for _ in range(N - 1):
    _c, _s, _f = [int(x) for x in input().split()]
    c.append(_c)
    s.append(_s)
    f.append(_f)

def solve(i):
    start_time = 0
    for j in range(i, N - 1):
        depart_time = get_dep_time(start_time, s[j], f[j])
        arrived_time = depart_time + c[j]
        start_time = arrived_time
    return arrived_time

def get_dep_time(start, s, f):
    t = max(start, s)
    return math.ceil(t / f) * f

for i in range(N - 1):
    print(solve(i))
print(0)
