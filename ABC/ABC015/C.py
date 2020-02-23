from itertools import product

N, K = [int(x) for x in raw_input().split()]
T = [[int(x) for x in raw_input().split()] for i in range(N)]

for s in product(*T):
    a = s[0]
    for i in range(1, len(s)):
        a ^= s[i]

    if not a:
        print "Found"
        break
else:
    print "Nothing"
