a = int(raw_input())
b = int(raw_input())

if a % b == 0:
    print 0
else:
    print b - a % b
