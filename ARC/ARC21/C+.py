from operator import itemgetter

def solve():
    K = int(raw_input())
    N = int(raw_input())
    A = []
    D = []
    for i in range(N):
        a, d = [int(x) for x in raw_input().split()]
        A.append(a)
        D.append(d)

    AD = zip(A, D)

    AD = sorted(AD, key=itemgetter(0))

    ans = 0
    t = 1
    while True:
        n = (AD[1][0] - AD[0][0])/AD[0][1] + 1
        ans += AD[0][0]*n +
        AD[0] = (AD[0][0]+AD[0][1], AD[0][1])
        if AD[0][0] > AD[0][1]:
            t += 1
            AD = sorted(AD[:t], key=itemgetter(0)) + AD[t:]

    print ans


if __name__ == '__main__':
    solve()
