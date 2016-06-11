N = int(raw_input())
R = [int(x) for x in raw_input().split()]


def count(l):
    ret = 0
    p = None
    if R[0] > l:
        p = 1
    else:
        p = -1

    for i in range(1, len(R)):
        if R[i] > l and p < 0:
            p = 1
            ret += 1
        if R[i] < l and p > 0:
            p = -1
            ret += 1

    return ret

m = 0
for r in R:
    l = r + 0.1
    m = max(count(l), m)
    l = r - 0.1
    m = max(count(l), m)

if m == 1:
    print 0
else:
    print m + 1
