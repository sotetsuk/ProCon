N = int(raw_input())
s1 = raw_input()
s2 = raw_input()

abc = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
dig = '1234567890'

ans = 1

dic = {}

def search(c):
    l = []
    for i in range(N):
        if s1[i] == c or s2[i] == c:
            l.append((s1[i], s2[i]))

    if c in dic:
        if dic[c] in dig:
            return dic[c]
    else:
        if len(l) == 0:
            return
        else:
            dic[c] = c

    for a, b in l:
        if a != c:
            a, b = b, a

        if b == c:
            pass
        elif b in dig:
            tmp = dic[c]
            for k, v in dic.items():
                if v == tmp:
                    dic[k] = b
        elif b in abc:
            if abc.find(c) < abc.find(b):
                dic[b] = dic[c]

def solve():
    for c in abc:
        search(c)

    ans = 1

    if s1[0] in abc and dic[s1[0]] in abc:
        ans *= 9
        for k, v in dic.items():
            if v == s1[0] or v == s2[0]:
                dic[k] = '0'

    for k, v in dic.items():
        if dic[k] in abc:
            if k == v:
                ans *= 10

    print ans

solve()
