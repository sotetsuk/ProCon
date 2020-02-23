dp = [0]*20
dp[1] = 2

def count_block(k):
    if dp[k] != 0:
        return dp[k]
    else:
        dp[k] = 10**(k-1)*2 + count_block(k-1)*8
        return dp[k]

def count(n):
    count = 0
    str_n = str(n)
    K = len(str_n)
    for k in range(K,0,-1):
        if k == 1:
            if 4 <= int(str_n[-1]) <=8:
                count += 1
            elif int(str_n[-1]) == 9:
                count += 2
            break
        i = K-k
        n_k = int(str_n[i])
        for j in range(n_k):
            if j == 4:
                count += 10**(k-1)
            else:
                count += count_block(k-1)
        if n_k == 4 or n_k == 9:
            count += int(str_n[K-k+1:]) + 1
            break

    return count

def solve():
    A, B = [int(x) for x in raw_input().split()]
    print count(B)-count(A-1)
    return

if __name__ == '__main__':
    solve()
