import math

N = int(raw_input())

C = [int(raw_input()) for _ in xrange(N)]
K = [0] * N

C.sort()

for i in range(N):
    for j in range(i+1, N):
        if C[j] % C[i] == 0:
            K[j] += 1

for i in range(N-1):
    if C[N-1-i] == C[N-2-i]:
        K[N-2-i] = K[N-1-i]

##
print C
print K


count = 0
for l in range(N):
    for i in range(N):
        k = K[l]

        if i == 0:
            count += 1
            continue

        j_max = 0
        if k%2 == 0 and i%2 == 0:
            j_max = min(k, i)
        elif k%2 == 1 and i%2 == 0:
            j_max = min(k-1, i)
        elif k%2 == 0 and i%2 == 1:
            j_max = min(k, i-1)
        else: # both odd
            j_max = min(k-1, i-1)

        for j in range(0, j_max+1, 2):
            tmp = 1
            tmp *= math.factorial(k)
            tmp *= math.factorial(i)
            tmp /= math.factorial(j)
            tmp /= math.factorial(i-j)
            if k - j >= 0 and N- i - 1 >= 0:
                tmp *= math.factorial(N-k-1)
                tmp *= math.factorial(N-i-1)
                tmp /= math.factorial(k-j)
                tmp /= math.factorial(N-i-1-k+j)

            count += tmp

            print "l:, ", l, "i: ", i, "j: ", j, "k: ", k, "tmp: ", tmp

print count
print 1.0*count/math.factorial(N)
