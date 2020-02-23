S = raw_input()
N = int(raw_input())
 
ret = []
for a in S:
    for b in S:
        ret.append(a + b)
 
ret = list(set(ret))
ret.sort()
 
print(ret[N - 1])
