#include "bits/stdc++.h"

struct P { long double x, y, r; };

bool check(long double val, const std::vector<P> &v) {
    int n = v.size();
    for (std::uint32_t i = 0; i < n; ++i) {
        for (std::uint32_t j = 0; j < n; ++j) {
            if (i == j) continue;
            auto x0 = v[i].x;
            auto y0 = v[i].y;
            auto r0 = v[i].r > -0.0 ? v[i].r : val;
            auto x1 = v[j].x;
            auto y1 = v[j].y;
            auto r1 = v[j].r > 0.0 ? v[j].r : val;
            auto d = std::sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
            if (d < r0 + r1) return false;
        }
    }
    return true;
}

int main() {
    std::int32_t N, M; std::cin >> N >> M;
    std::vector<P> v;
    long double min_r = 1e5;
    for (std::uint32_t i = 0; i < N; ++i) {
        long double x, y, r; std::cin >> x >> y >> r;
        v.emplace_back(P{x, y, r});
        min_r = std::min(min_r, r);
    }
    for (std::uint32_t i = 0; i < M; ++i) {
        long double x, y; std::cin >> x >> y;
        v.emplace_back(P{x, y, -1.0});
    }
    long double l = 0.0, r = 1000.0;
    while (r - l > 1e-8) {
        long double m = (l + r) / 2.0;
        if (check(m, v)) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << std::setprecision(8);
    if (M != 0) {
        std::cout << l << std::endl;
    } else {
        std::cout << min_r << std::endl;
    }
    return 0;
}
