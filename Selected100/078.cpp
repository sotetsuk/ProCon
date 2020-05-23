#include "bits/stdc++.h"

int main() {
    std::int32_t M, N, K; std::cin >> M >> N >> K;
    std::vector<std::string> grid;
    for (std::uint32_t i = 0; i < M; ++i) {
        std::string s; std::cin >> s;
        grid.push_back(s);
    }
    std::vector<std::vector<std::int32_t>> J(M + 1, std::vector<std::int32_t>(N + 1, 0));
    std::vector<std::vector<std::int32_t>> O(M + 1, std::vector<std::int32_t>(N + 1, 0));
    std::vector<std::vector<std::int32_t>> I(M + 1, std::vector<std::int32_t>(N + 1, 0));
    for (std::uint32_t i = 0; i < M; ++i) {
        for (std::uint32_t j = 0; j < N; ++j) {
            J[i+1][j+1] = J[i+1][j] + (grid[i][j] == 'J' ? 1 : 0);
            O[i+1][j+1] = O[i+1][j] + (grid[i][j] == 'O' ? 1 : 0);
            I[i+1][j+1] = I[i+1][j] + (grid[i][j] == 'I' ? 1 : 0);
        }
    }
    // std::cout << "===" << std::endl;
    // for (std::uint32_t i = 0; i < M + 1; ++i) {
    //     for (std::uint32_t j = 0; j < N + 1; ++j) {
    //         std::cout << J[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    for (std::uint32_t j = 0; j <= N; ++j) {
        for (std::uint32_t i = 0; i < M; ++i) {
            J[i+1][j] += J[i][j];
            O[i+1][j] += O[i][j];
            I[i+1][j] += I[i][j];
        }
    }
    // std::cout << "===" << std::endl;
    // for (std::uint32_t i = 0; i < M + 1; ++i) {
    //     for (std::uint32_t j = 0; j < N + 1; ++j) {
    //         std::cout << J[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << "===" << std::endl;
    for (std::uint32_t k = 0; k < K; ++k) {
        std::int32_t a, b, c, d; std::cin >> a >> b >> c >> d;
        --a; --b;
        std::cout << J[c][d] - J[a][d] - J[c][b] + J[a][b] << " ";
        std::cout << O[c][d] - O[a][d] - O[c][b] + O[a][b] << " ";
        std::cout << I[c][d] - I[a][d] - I[c][b] + I[a][b] << std::endl;
    }
    return 0;
}
