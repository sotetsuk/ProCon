import sys
sys.stdout = open(sys.argv[1], 'w')

def solve(A, B, K):
    count = 0
    for i in range(A):
        for j in range(B):
            if i&j < K:
                count += 1

    return count

if __name__ == '__main__':
    T = int(raw_input())
    for i in range(T):
        A, B, K = [int(x) for x in range(3)]
        ret = solve(A, B, K)
        sys.stdout.write("Case #{}: {}\n".format(i+1, ret))
