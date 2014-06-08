n, m, k = [int(x) for x in raw_input().split()]

x, y = 1, 1
i = 1

def return_next(x, y):
    if x % 2 == 1:
        if y < m:
            return x, y+1
        else:
            return x+1, y
    else:
        if y > 1:
            return x, y-1
        else:
            return x+1, y

while i < k:
    ret = "2 "
    ret += str(x) + " " + str(y) + " "
    x, y = return_next(x, y)
    ret += str(x) + " " + str(y) + " "
    x, y = return_next(x, y)
    print ret
    i += 1

c = 0
ret = ""

goal_x, goal_y = (n, m) if n%2 == 1 else (n, 1)
while not (x == goal_x and y == goal_y):
    ret += str(x) + " " + str(y) + " "
    x, y = return_next(x, y)
    c += 1
else:
    ret += str(x) + " " + str(y)
    c += 1

print str(c) + " " + ret
