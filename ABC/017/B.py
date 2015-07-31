X = raw_input()

X = X[::-1]

while len(X):
    if X[0] == 'o' or X[0] == 'k' or X[0] == 'u':
        X = X[1:]
    elif X[0] == 'h':
        if len(X) > 1 and X[1] == 'c':
            X = X[2:]
        else:
            print "NO"
            break
    else:
        print "NO"
        break
else:
    print "YES"
