a, k  = raw_input().split()
k = int(k)

m = 1e16
for i in range(len(a)):
    for j in range(10):
        for l in range(10):
            s = a[:i] + str(j)
            s += str(l) * (len(a) - len(s))
            if len(s) > 1 and s[0] == '0':
                s = s[1:]
            if len(set(s)) <= k:
                m = min(m, abs(int(a) - int(s)))
print m
