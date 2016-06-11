n = int(raw_input())
a = [int(x) for x in raw_input().split()]

s = 0
for i in a:
    s += s + i

print s
