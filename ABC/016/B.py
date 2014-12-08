a, b, c = [int(x) for x in raw_input().split()]

if a + b == c and a - b == c:
    print "?"
elif a + b == c:
    print "+"
elif a - b == c:
    print "-"
else:
    print "!"
