def judge(a, b, c, d):
    c, d = c + 0.01, d + 0.01

    a, b = min(a, b) * 1., max(a, b) * 1.
    c, d = min(c, d), max(c, d)
    if a < c and b < d:
        return True
    if a > c:
        return False

    if (b ** 2 - a ** 2) ** .5 * d > b:
        return True

if __name__ == '__main__':
    a, b = [int(x) for x in raw_input().split()]
    N = int(raw_input())

    for i in range(N):
        c, d = [int(x) for x in raw_input().split()]
        if judge(a, b, c, d):
            print "YES"
        else:
            print "NO"
