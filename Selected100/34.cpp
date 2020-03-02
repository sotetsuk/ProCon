//
// Created by Sotetsu KOYAMADA on 2020/03/02.
//

#include <iostream>
#include <vector>

int fib(int n, std::vector<int> &dp) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> dp(n+1, -1);
    std::cout << fib(n, dp) << std::endl;
}