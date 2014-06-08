n = int(raw_input())
s = [int(x) for x in raw_input().split()]
m = int(raw_input())
s2 = [[i, i] for i in xrange(1, n+1)]

if s == range(1, n+1):
    print m
    ret = ""
    for i in range(2, m+2):
        ret += "1 " + str(i) + " "
    print ret
else:
    p = []
    for i, ab in enumerate(s2[::]):
        a, b = ab
        if b != s[i]:
                        
