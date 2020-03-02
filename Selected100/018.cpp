//
// Created by Sotetsu KOYAMADA on 2020/03/02.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

bool find(int target, const std::vector<int> &v)
{
    int l = 0, r = v.size(), m;
    while (r - l > 1)
    {
        m = l + (r - l) / 2;
        if (v[m] > target) {
            r = m;
        } else {
            l = m;
        }
    }
    return v[l] == target;
}

int main()
{
    int n, q;
    std::set<int> s;
    std::vector<int> t;

    std::cin >> n;
    int tmp;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        s.insert(tmp);
    }
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> tmp;
        t.push_back(tmp);
    }

    std::sort(t.begin(), t.end());

    int ans = 0;
    for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        if (find(*it, t)) ++ans;
    }
    std::cout << ans << std::endl;
}