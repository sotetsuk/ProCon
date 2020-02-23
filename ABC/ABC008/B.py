from collections import defaultdict

dic = defaultdict(int)
N = int(raw_input())

for i in range(N):
    name = raw_input()
    dic[name] += 1

m = 0
ans = ""
for k, v in dic.items():
    if v > m:
        ans = k
        m = v

print(ans)
