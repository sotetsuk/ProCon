N, K = [int(x) for x in raw_input().split()]
X = [int(x) for x in raw_input().split()]
r = [i for i in range(1, N + 1)]

l = [(X[i], r[i]) for i in xrange(K)]

l.sort()
print l[K - 1][1]

for i in xrange(K, N):
    l.append((X[i], r[i]))
    l.sort()
    l = l[:K]

    print l[K - 1][1]
