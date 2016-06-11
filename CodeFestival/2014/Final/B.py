s = raw_input()

ans = 0
for i, c in enumerate(s):
    if i % 2 == 0:
        ans += int(c)
    else:
        ans -= int(c)

print ans
