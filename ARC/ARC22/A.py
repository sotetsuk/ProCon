s = raw_input()
s = s.upper()

for x in "ICT":
    t = s.find(x)
    if t != -1:
        s = s[t+1:]
    else:
        print "NO"
        break
else:
    print "YES"
