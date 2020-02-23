N, A, B = [int(x) for x in raw_input().split()]

N %= A + B

if 0 < N <= A:
    print "Ant"
else:
    print "Bug"
