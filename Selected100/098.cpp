#include <bits/stdc++.h>

const std::uint64_t mod = 1000000007;

int main() {
    std::uint32_t N; std::cin >> N;
    std::uint32_t cnt[3] = {0, 0, 0};
    std::uint64_t ans = 1;
    for (std::uint32_t i = 0; i < N; ++i) {
        std::uint32_t a; std::cin >> a;
        std::uint32_t c = 0;
        ans *= c;
        ans %= mod;
        for (std::uint32_t j = 0; j < 3; ++j) {
            if (cnt[j] == a) {
                cnt[j]++;
                break;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
