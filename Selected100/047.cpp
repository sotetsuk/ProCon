#include <bits/stdc++.h>

const std::uint32_t MAX_N = 2005;
std::uint32_t N;
std::int64_t dp[MAX_N][MAX_N][2];
std::int64_t A[MAX_N];

std::int64_t fit(std::int32_t i) {
    if (i == -1) return N - 1;
    if (i == N) return 0;
    return i;
}

std::int64_t dfs(std::int32_t i, std::int32_t j, std::int32_t turn) {
    i = fit(i), j = fit(j);
    if (i == j) return 0;
    if (dp[i][j][turn%2] != -1) return dp[i][j][turn%2];
    if (turn % 2 == 1) {
        if (A[i] > A[fit(j - 1)]) {
            return dp[i][j][turn%2] = dfs(i + 1, j, turn + 1);
        } else {
            return dp[i][j][turn%2] = dfs(i, j - 1, turn + 1);
        }
    } else {
        auto a = A[i] + dfs(i + 1, j, turn + 1);
        auto b = A[fit(j - 1)] + dfs(i, j - 1, turn + 1);
        return dp[i][j][turn%2] = std::max(a, b);
    }
}

int main() {
    std::cin >> N;
    for (std::uint32_t i = 0; i < N; ++i) std::cin >> A[i];
    memset(dp, -1, sizeof(dp));
    std::int64_t ans = 0;
    for (std::uint32_t i = 0; i < N; ++i) {
        ans = std::max(ans, A[i] + dfs(i + 1, i, 1));
    }
    std::cout << ans << std::endl;
    return 0;
}
