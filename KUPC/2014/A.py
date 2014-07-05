x = [int(x) for x in raw_input().split()]
a = x[:3]
b = x[3:]

l = [abs(a[0]-b[0]) + abs(a[1]-b[1]) + abs(a[2] - b[2]),
     abs(a[0]-b[0]) + abs(a[1]-b[2]) + abs(a[2] - b[1]),
     abs(a[0]-b[1]) + abs(a[1]-b[0]) + abs(a[2] - b[2]),
     abs(a[0]-b[1]) + abs(a[1]-b[2]) + abs(a[2] - b[0]),
     abs(a[0]-b[2]) + abs(a[1]-b[0]) + abs(a[2] - b[1]),
     abs(a[0]-b[2]) + abs(a[1]-b[1]) + abs(a[2] - b[0])]

print min(l)
