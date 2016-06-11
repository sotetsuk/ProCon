X = int(raw_input())


def f(X):
    x = str(X)
    ret = 1
    for i in x:
        ret *= int(i)
    return ret


while X >= 10:
    X = f(X)

print X
