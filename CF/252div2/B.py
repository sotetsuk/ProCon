n, v = [int(x) for x in raw_input().split()]
ab_list = [[int(x) for x in raw_input().split()] for _ in xrange(n)]

ab_list.sort()

a_list = []
b_list = []
for i, ab in enumerate(ab_list):
    a, b = ab
    if i == 0:
        a_list.append(a)
        b_list.append(b)
    else:
        if a_list[i-1] == a:
            b_list[i-1] += b
        else:
            a_list.append(a)
            b_list.append(b)

c = 0
rest = 0
a_bef = 0

for a, b in zip(a_list, b_list):
    if a_bef != a-1:    
        c += min(rest, v)
        rest = 0

    cap = v
    if cap <= rest:
        c += cap
        rest = b
    else:
        cap -= rest
        c += rest
        c += min(b, cap)
        rest = max(0, b-cap)
    a_bef = a

else:
    c += min(rest, v)

print c
