import math

N, X = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

ans = None
for a in A:
    x = int(abs(a - X))
    if ans is None:
        ans = x
    else:
        ans = math.gcd(ans, x)

print(ans)
