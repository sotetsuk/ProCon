from itertools import permutations

def check():
    for i in range(3):
        for j in range(5):
            if M[i][j] < M[i + 1][j] < M[i + 2][j]:
                return False
            if M[i][j] > M[i + 1][j] > M[i + 2][j]:
                return False
    for i in range(5):
        for j in range(3):
            if M[i][j] < M[i][j + 1] < M[i][j + 2]:
                return False
            if M[i][j] > M[i][j + 1] > M[i][j + 2]:
                return False

    return True




if __name__ == '__main__':
    M = [[int(x) for x in raw_input().split()] for _ in range(5)]

    ix_list = []
    for i in range(5):
        for j in range(5):
            if M[i][j] == 0:
                ix_list.append((i, j))

    exist_list = []
    for i in range(5):
        for j in range(5):
            if M[i][j] != 0:
                exist_list.append(M[i][j])

    candidate_list = []
    for i in range(1, 26):
        if not i in exist_list:
            candidate_list.append(i)


    ans = 0
    for x in permutations(candidate_list):
        for h, ij in enumerate(ix_list):
            i, j = ij
            M[i][j] = x[h]

        if(check()):
            ans += 1

        for i, j in ix_list:
            M[i][j] = 0

    print(ans)