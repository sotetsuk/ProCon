def solve():
    s = raw_input()
    if s == 'a':
        print -1
    elif len(s) == 1:
        print 'a'
    else:
        print 'a'*(len(s)-1)

if __name__ == '__main__':
    solve()
