def solve(N, strings):
    s1 = strings[0]
    s2 = strings[1]
    if len(s1) > len(s2):
        s1, s2 = s2, s1

    count = 0
    while True:
        if s1 == s2:
            break
        else:
            for i in range(len(s1[::])):
                if s1[i] == s2[i]:
                    pass
                else:
                    if i == 0:
                        return "Fegla Won1"
                    else:
                        if s1[i] == s1[i-1]:
                            s1 = s1[:i-1] + s1[i:]
                            count += 1
                        elif s2[i] == s2[i-1]:
                            s2 = s2[:i-1] + s2[i:]
                            count += 1
                        else:
                            return "Fegla Won2"

    return str(count+1)

if __name__ == '__main__':
    T = int(raw_input())
    for i in xrange(T):
        N = int(raw_input())
        strings = [raw_input() for _ in xrange(N)]
        print "Case #" + str(i+1) + ": " + solve(N, strings)
