M = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
dp = dict()

def calc_points(b, c, M):
    chokudai = 0
    naoko = 0
    for i in range(2):
        for j in range(3):
            if M[i][j] * M[i + 1][j] > 0:
                chokudai += b[i][j]
            else:
                naoko += b[i][j]

    for i in range(3):
        for j in range(2):
            if M[i][j] * M[i][j + 1] > 0:
                chokudai += c[i][j]
            else:
                naoko += c[i][j]

    return chokudai, naoko

def dfs(n):
    if n == 10:
        return calc_points(b, c, M)

    str_M = M2str(M)
    if dp.has_key(str(n) + str_M):
        return dp[str(n) + str_M]

    s = 1 if n % 2 == 1 else -1
    m = 0
    ret = None

    for i in range(3):
        for j in range(3):
            if M[i][j] == 0:
                M[i][j] = s
                r = dfs(n + 1)
                if s > 0:
                    if r[0] >= m:
                        m = r[0]
                        ret = r
                if s < 0:
                    if r[1] >= m:
                        m = r[1]
                        ret = r
                M[i][j] = 0

    dp[str(n) + str_M] = ret
    return ret

def M2str(M):
    ret = ""
    for i in range(3):
        for j in range(3):
            ret += str(M[i][j])

    return ret



if __name__ == '__main__':
    b = [[int(x) for x in raw_input().split()] for _ in range(2)]
    c = [[int(x) for x in raw_input().split()] for _ in range(3)]

    ans = dfs(1)
    print(ans[0])
    print(ans[1])


