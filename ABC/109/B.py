N = int(input())
d = {}
last = None
flag = True

for _ in range(N):
    word = input()
    if word in d.keys():
        flag = False
    else:
        d[word] = 1

    if last is not None and last != word[0]:
        flag = False
    else:
        last = word[-1]

if flag:
    print("Yes")    
else:
    print("No")