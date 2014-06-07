n = int(raw_input())
f = [int(x) for x in raw_input().split()]

c = 0
for a in f:
    b = a % 6
    if b == 2 or b == 4:
        c += 1
    elif b == 5:
        c += 2
    elif b == 0:
        c += 3

print(c)
