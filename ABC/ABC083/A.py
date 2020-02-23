a, b, c, d = [int(x) for x in input().split()]
left = a + b
right = c + d
if left > right:
    print("Left")
elif left == right:
    print("Balanced")
else:
    print("Right")
