n, y = [int(x) for x in input().split()]

for i in range(n + 1):
    for j in range(i, n + 1):
        m = i
        g = j - i
        s = n - j
        if y == m * 10000 + g * 5000 + s * 1000:
            print("{} {} {}".format(m, g, s))
            exit()

print("-1 -1 -1 ")
