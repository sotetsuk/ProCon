def proceed(d, A, B):
    if d > B:
        return B
    elif A < d <= B:
        return d
    else:
        return A

if __name__ == '__main__':
    N, A, B = [int(x) for x in raw_input().split()]

    p = 0
    for _ in range(N):
        s, d = raw_input().split()
        d = proceed(int(d), A, B)
        p += d if s == "East" else - d

    destination = ""
    if p > 0:
        destination = "East "
    elif p < 0:
        destination = "West "

    ans = destination + str(abs(p))
    print(ans)