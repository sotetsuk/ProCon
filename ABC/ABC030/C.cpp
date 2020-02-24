//
// Created by Sotetsu KOYAMADA on 2020/02/25.
//

#include <vector>
#include <iostream>


int main()
{
    int N, M, X, Y;
    std::cin >> N >> M >> X >> Y;
    std::vector<int> a(N);
    std::vector<int> b(M);
    for (int i = 0; i < N; ++i) std::cin >> a[i];
    for (int i = 0; i < M; ++i) std::cin >> b[i];

    int curr = 0;
    int ans = 0;
    while (true)
    {
        auto it = std::lower_bound(a.begin(), a.end(), curr);
        if (it == a.end()) break;
        curr = *it + X;
        it = std::lower_bound(b.begin(), b.end(), curr);
        if (it == b.end()) break;
        curr = *it + Y;
        ++ans;
    }
    std::cout << ans << std::endl;
}

