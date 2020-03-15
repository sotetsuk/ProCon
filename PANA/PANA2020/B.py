H, W = [int(x) for x in input().split(" ")]

def f(h, w):
    if h == 1 or w == 1:
        return 1
    if h % 2 == 0 and w % 2 == 0:
        return (h // 2) * w
    elif h % 2 == 1 and w % 2 == 0: 
        return f(h - 1, w) + w // 2
    elif h % 2 == 0 and w % 2 == 1: 
        return f(h, w - 1) + h // 2
    else:
        return f(h - 1, w) + w // 2 + 1

print(f(H, W))
