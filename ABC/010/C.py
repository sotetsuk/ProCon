import math

txa, tya, txb, tyb, T, V = [int(a) for a in raw_input().split()]
n = int(raw_input())
xy_list = [[int(a) for a in raw_input().split()] for _ in range(n)]

max_r = T*V
for xy in xy_list:
    x, y = xy
    r = math.sqrt((txa - x)**2 + (tya - y)**2) + math.sqrt((txb - x)**2 + (tyb - y)**2)
    if r <= max_r:
        print("YES")
        break
else:
    print("NO")
