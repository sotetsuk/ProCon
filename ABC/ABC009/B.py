N = int(raw_input())
a = [int(raw_input()) for _ in range(N)]
a = list(set(a))
a.sort()
print a[-2]
