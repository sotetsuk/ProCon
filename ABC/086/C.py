N = int(input())

t_prev, x_prev, y_prev = 0, 0, 0
for _ in range(N):
    t, x, y = [int(x) for x in input().split()]
    l = (t - t_prev) - ((x - x_prev) + (y - y_prev))
    if not (l >= 0 and l % 2 == 0):
        print("No")
        exit()

print("Yes")
