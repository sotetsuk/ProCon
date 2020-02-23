s = input()
t = input()

s = list(s)
s.sort()

t = list(t)
t.sort()
t.reverse()

ans = "Yes" if ''.join(s) < ''.join(t) else "No"
print(ans)
