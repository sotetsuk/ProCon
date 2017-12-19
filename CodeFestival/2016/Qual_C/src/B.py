K, T = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]


def argmax(l, excep):
    m = -1
    ix = -1

    for i, e in enumerate(l):
        if i == excep:
            continue

        if e > m:
            m = e
            ix = i

    return ix, m


t = sum(a)
b = -1
ans = 0

for i in range(t):
    ix, m = argmax(a, b)

    if m > 0:
        b = ix
        a[ix] -= 1

    else:
        if b == -1:
            break

        if a[b] != 0:
            ans += 1
            a[b] -= 1
        else:
            break

print(ans)