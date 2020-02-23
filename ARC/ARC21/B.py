def solve():
    L = int(raw_input())
    B = []
    A = [0]
    for i in range(L):
        B.append(int(raw_input()))
        A.append(B[i]^A[i])
    if A[-1] != 0:
        print -1
    else:
        for i in A[:-1]:
            print i

if __name__ == '__main__':
    solve()
