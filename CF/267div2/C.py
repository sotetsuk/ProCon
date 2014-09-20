n, m, k = [int(x) for x in raw_input().split()]
p = [int(x) for x in raw_input().split()]
MIN_INF = -2*10**9

ans = 0
for i in xrange(k):

    print "="*50 ## debug

    f_ix = 0
    e_ix = f_ix + m - 1
    t = 0
    for i in range(f_ix, e_ix + 1):
        t += p[i]

    m_ix = f_ix
    t_m = t

    while(e_ix < len(p) - 1):
        f_ix += 1
        e_ix += 1

        print f_ix, e_ix ## debug

        t = t - p[f_ix - 1] + p[e_ix]
        if t_m < t:
            m_ix = f_ix
            t_m = t
    ans += t_m
    print t_m ## debug
    print p[m_ix:m_ix+m] ## debug
    for j in xrange(m_ix, m_ix + m):
        p[j] = MIN_INF
    print p ## debug

print ans
