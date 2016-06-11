n = int(raw_input())
a = [int(x) for x in raw_input().split()]

s = 0
for i in range(len(a) - 1):
    s += a[i]

print 1. * (s - a[0] + a[-1]) / (len(a) - 1) - 1. * s / (len(a) - 1)
