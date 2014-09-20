def get_sum(c):
    ret = 0
    for i in c:
        ret += int(i)

    return ret

if __name__ == "__main__":
    n, m, k = [int(x) for x in raw_input().split()]

    l = []
    for i in range(m):
        l.append(int(raw_input()))
    x = int(raw_input())

    s = 0
    for y in l:
        if get_sum(bin(x ^ y)[2:]) <= k:
            s += 1

    print s
