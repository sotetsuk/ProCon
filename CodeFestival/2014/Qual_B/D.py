N = int(raw_input())
h = [int(raw_input()) for _ in range(N)]

a = [0 for _ in range(N)]
for i in xrange(len(h)):
    for j in xrange(i+1, len(h)):
        if h[j] <= h[i]:
            a[i] += 1
        else:
            break

for i in xrange(len(h)):
    for j in xrange(i-1, -1, -1):
        if h[j] <= h[i]:
            a[i] += 1
        else:
            break

for c in a:
    print c
