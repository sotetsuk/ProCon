A = int(raw_input())

for i in range(A+1):
    if i*i*i == A:
        print "YES"
        break
else:
    print "NO"
