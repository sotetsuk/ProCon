N = int(input())
X = input()

def count_bits(x):
    cnt = 0
    while x:
        x = x&(x-1)
        cnt += 1
    return cnt

def f(x):
    cnt = 0
    while x:
        x %= count_bits(x)
        cnt += 1
    return cnt


def flip(X, i):
    a = '0' if X[i] == '1' else '0'
    return X[:i] + a + X[i+1:]

for i in range(N):
    X_flipped = flip(X, i)
    x = int(X_flipped, 2)
    print(x)
    print(f(x))