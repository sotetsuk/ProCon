def solve(n, a):
    j = 0
    for i in xrange(n):
        if i > 0 and a[i-1] > a[i]:
            j = i
            break
    else:
        print 0
        return

    a = a[j:] + a[:j]
    for i in xrange(n):
        if i > 0 and a[i-1] > a[i]:
            print -1
            return
    else:
        print n - j

if __name__ == '__main__':
    n = int(raw_input())
    a = [int(x) for x in raw_input().split()]

    solve(n, a)
