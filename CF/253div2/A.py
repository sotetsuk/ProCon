s = set([x.strip() for x in raw_input()[1:-1].split(',')])
if '' in s:
    print(0)
else:
    print(len(s))
