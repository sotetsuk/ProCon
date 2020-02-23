D = [int(x) for x in raw_input().split()]
J = [int(x) for x in raw_input().split()]

ans = 0
for i in range(7):
    ans += max(D[i], J[i])

print ans
