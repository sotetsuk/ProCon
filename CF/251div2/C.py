n, k, p = [int(x) for x in raw_input().split()]
a = [int(x) for x in raw_input().split()]

evens = []
odds = []

for x in a:
    if x%2 == 0:
        evens.append(x)
    else:
        odds.append(x)

if k-p > len(odds):
    print "NO"
elif (len(odds)-(k-p)) % 2 == 1:
    print "NO"
elif (len(odds)-(k-p))/2 + len(evens) < p:
    print "NO"
else:
    print "YES"
    m = 0
    i = 0
    while i < k-p:
        print "1", str(odds[i])
        i += 1
        m += 1
    while i < len(odds) and m < k-1:
        print "2", str(odds[i]), str(odds[i+1])
        i += 2
        m += 1
    c = 0
    l = ""
    while i < len(odds):
        l += " " + str(odds[i])
        i += 1
        c += 1
    j = 0
    while m < k-1:
        print "1", str(evens[j])
        j += 1
        m += 1
    while j < len(evens):
        l += " " + str(evens[j])
        c += 1
        j += 1
    l = str(c) + l
    if c > 0:
        print l
