x1, y1, x2, y2 = [int(x) for x in input().split()]

x4 = x1 - (y2 - y1)
y4 = y1 + (x2 - x1)
x3 = x2 + x4 - x1
y3 = y2 + y4 - y1

print("{} {} {} {}".format(x3, y3, x4, y4))