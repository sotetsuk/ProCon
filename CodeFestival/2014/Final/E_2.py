N = int(raw_input())
R = [int(x) for x in raw_input().split()]


def get_next(i, p):
    for j in range(i + 1, N):
        if p > 0 and R[j] > R[i]:
            return j
        if p < 0 and R[j] < R[i]:
            return j

    return


def solve(init_p):
    p = init_p
    i = 0
    count = 1
    while i < N:
        j = get_next(i, p)
        if j is None:
            break
        else:
            i = j
            count += 1
            p = -p

    return count

ans = solve(1)
ans = max(solve(-1), ans)

if ans < 3:
    print 0
else:
    print ans
