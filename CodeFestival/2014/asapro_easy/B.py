n = int(raw_input())

i = 1
t = 1

p = True

while i <= n:
    if i == n:
        print t

    if p:
        t += 1
    else:
        t -= 1

    if t == 21:
        t = 20
        p = False
    if t == 0:
        t = 1
        p = True

    i += 1
