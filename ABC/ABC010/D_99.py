N, G, E = [int(x) for x in raw_input().split()]
p_list = [int(x) for x in raw_input().split()]
ab_list = [[int(x) for x in raw_input().split()] for _ in range(E)]

bool_list = []
visited_list = []

def change_to_bool(n):
    ret = [bool(int(x)) for x in bin(n)[2:]]
    if len(ret) < E:
        ret = [False]*(E-len(ret)) + ret
    return ret


def dfs(w):
    if visited_list[w]:
        return
    else:
        visited_list[w] = True
        for i, ab in enumerate(ab_list):
            a, b = ab
            if bool_list[i]:
                if a == w:
                    dfs(b)
                if b == w:
                    dfs(a)
        return

m = 2**31-1
for i in xrange(2**E):
    bool_list = change_to_bool(i)
    visited_list = [False]*N

    dfs(0)

    c = 0
    for p in p_list:
        if visited_list[p]:
            c += 1

    m = min(m, (E-sum(bool_list)) + c)

print m
