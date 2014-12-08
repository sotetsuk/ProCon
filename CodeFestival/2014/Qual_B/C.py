import sys
from collections import defaultdict

s1 = raw_input()
s2 = raw_input()
s3 = raw_input()

def get_dic(s):
    dic = defaultdict(int)
    for c in s:
        dic[c] += 1
    return dic

dic1 = get_dic(s1)
dic2 = get_dic(s2)
dic3 = get_dic(s3)

n = len(s3) / 2

# print dic1 ##
# print dic2 ##
# print dic3 ##

n1 = n
n2 = n
r = ""
for c in 'abcdefghijklmnopqrstuvwxyz'.upper():
    if dic3[c] > dic1[c] + dic2[c]:
        print "NO"
        sys.exit()
    elif dic3[c] == dic1[c] + dic2[c]:
        n1 -= dic1[c]
        n2 -= dic2[c]
    else:
        r += c

for c in r:
    if dic3[c] <= dic1[c]:
        n1 -= dic3[c]
    else:
        n1 -= dic1[c]
        n2 -= (dic3[c] - dic1[c])

# print dic1 ##
# print dic2 ##
# print dic3 ##


if n1 > 0:
    print "NO"
    sys.exit()
if n1 == 0:
    print "YES"
    sys.exit()

for c in r:
    if n1 >= 0:
        print "YES"
        sys.exit()
    if dic2[c] > 0:
        n1 += min(dic2[c], dic3[c])
        n2 -= min(dic2[c], dic3[c])

print "NO"
