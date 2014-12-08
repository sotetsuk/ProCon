import sys

A = int(raw_input())

def get_num(n):
    n_s = str(n)
    base = n
    c = len(n_s) - 1
    ret = 0
    for i in range(len(n_s)):
        ret += int(n_s[i]) * (base ** c)
        c -= 1

    return ret

if A < 10:
    print -1
    sys.exit()

n = 2
while True:
    t = get_num(n)
    if t == A:
        print n
        break
    if t > 10e16:
        print -1
        break
    n += 1
