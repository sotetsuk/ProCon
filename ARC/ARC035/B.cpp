//
// Created by Sotetsu KOYAMADA on 2020/02/25.
//

#include <vector>
#include <iostream>
#include <algorithm>

const int M = 1'000'000'007;

unsigned long long count(const std::vector<int> &v)
{
    unsigned long long ret = 0;
    unsigned long long curr = 0;
    for (auto e: v)
    {
        curr = curr + e;
        ret += curr;
    }
    return ret;
}

unsigned long long perm(int n)
{
    if (n <= 1) return 1;
    return ((perm(n - 1) % M) * n) % M;
}

unsigned long long sum_perm(const std::vector<int> &v)
{
    unsigned long long ret = 1;
    int c = 1;
    int pre = -1;
    for (auto e: v)
    {
        if (pre == e)
        {
            ++c;
        } else {
            ret *= perm(c);
            // std::cout << "c "  << c << std::endl;
            ret %= M;
            pre = e;
            c = 1;
        }
    }
    ret *= perm(c);
    // std::cout << "c "  << c << std::endl;
    ret %= M;
    return ret;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    for (int i = 0; i < N; ++i) std::cin >> v[i];

    std::sort(v.begin(), v.end());
    std::cout << count(v) << std::endl;
}

