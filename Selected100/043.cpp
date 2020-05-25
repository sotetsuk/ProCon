#include <bits/stdc++.h>

int main() {
    std::int32_t N; std::cin >> N;
    std::vector<std::string> v(5);
    for (std::uint32_t i = 0; i < 5; ++i) {
        std::cin >> v[i];
    }
    std::vector<std::vector<std::int32_t>> dp(N+1, std::vector<std::int32_t> (3, INT_MAX));
    for (std::uint32_t j = 0; j < 3; ++j) {
        dp[0][j] = 0;
    }
    for (std::uint32_t i = 0; i < N; ++i) {
        std::vector<std::int32_t> n(3, 5);
        for (std::uint32_t j = 0; j < 5; ++j) {
            switch (v[j][i]) {
                case 'R':
                    n[0]--;
                    break;
                case 'B':
                    n[1]--;
                    break;
                case 'W':
                    n[2]--;
                    break;
            }
        }
        // std::cout << n[0] << n[1] << n[2]<< std::endl;
        for (std::uint32_t c1 = 0; c1 < 3; ++c1) {
            for (std::uint32_t c2 = 0; c2 < 3; ++c2) {
                if (c1 == c2) continue;
                dp[i+1][c1] = std::min(dp[i+1][c1], dp[i][c2] + n[c1]);
            }
        }
    }
    std::int32_t ans = INT_MAX;
    // for (std::uint32_t i = 0; i < N + 1; ++i) {
    //     for (std::uint32_t j = 0; j < 3; ++j) {
    //         std::cout << dp[i][j];
    //     }
    //     std::cout << std::endl;
    // }
    for (std::uint32_t j = 0; j < 3; ++j) {
        ans = std::min(ans, dp[N][j]);
    }
    std::cout << ans << std::endl;
    return 0;
}
