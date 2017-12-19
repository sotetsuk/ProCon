DIV = 10**9 + 7

N = int(input())
T = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]


def get_range(a, b):
    if b > a:
        return b, b
    if b == a:
        return (1, b)


left = [(T[0], T[0])]
right = [(A[-1], A[-1])]
for i in range(N - 1):
    a, b = T[i], T[i + 1]
    left.append(get_range(a, b))
    a, b = A[N - i - 1], A[N - i - 2]
    right.append(get_range(a, b))
right = right[::-1]


ans = 1
for i in range(N):
    a1, b1 = left[i]
    a2, b2 = right[i]

    a = max(a1, a2)
    b = min(b1, b2)

    ans *= max((b - a + 1), 0)
    ans %= DIV


print(ans)