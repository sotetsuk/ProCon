def solve(N, strings):
    i_N = [0]*N
    while(i_N[0] < len(strings[0])):
        t = strings[0][i_N[0]]
        for j in range(N):
            if strings[j][i_N[j]] == t:
                pass
            else:
                pass
        i_N[0] += 1

if __name__ == '__main__':
    T = int(raw_input())
    for i in xrange(T):
        N = int(raw_input())
        strings = [raw_input() for _ in xrange(N)]
        print "Case #" + str(i+1) + ": " + solve(N, strings)
