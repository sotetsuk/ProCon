//
// Created by Sotetsu KOYAMADA on 2020/03/02.
//

#include <iostream>

int solve(int n, int t)
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            for (int k = j + 1; k <= n; ++k)
                if (i + j + k == t) ++ans;
    return ans;
}

int main()
{
    int n, x;
    while (true) {
        std::cin >> n >> x;
        if (n == 0 && x == 0) break;
        std::cout << solve(n, x) << std::endl;
    }
    return 0;
}