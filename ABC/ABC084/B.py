a, b = [int(x) for x in input().split()]
s = input()
pre, aft = s[:a], s[a+1:]
h = s[a]

ans = 'Yes'

if '-' in pre:
    ans = 'No'

if '-' in aft:
    ans = 'No'

if h != '-':
    ans = 'No'

if len(aft) != b:
    ans = 'No'

print(ans)
