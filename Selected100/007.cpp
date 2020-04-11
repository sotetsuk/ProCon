#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

// namespace
using namespace std;
namespace mp = boost::multiprecision;

// types
using pii = pair<int, int>;
using ll = long long int;
using ld = long double;
using mpi = mp::cpp_int;
using mpf = mp::number<mp::cpp_dec_float<1024>>;

int main() {
    int n, a, b;
    set<pair<int, int>> s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        s.insert(make_pair(a, b));
    }
    double ans = 0;
    for (auto kv1: s) {
        for (auto kv2: s) {
            double x0, y0, x1, y1, x2, y2, x3, y3;
            x0 = kv1.first;
            y0 = kv1.second;
            x1 = kv2.first;
            y1 = kv2.second;
            if (x0 == x1 && y0 == y1) continue;
            double xm = (x0 + x1) / 2;
            double ym = (y0 + y1) / 2;
            x2 = xm - (y0 - ym);
            y2 = ym + (x0 - xm);
            x3 = xm + (y0 - ym);
            y3 = ym - (x0 - xm);
            if (x2 - static_cast<int>(x2) != 0) continue;
            if (y2 - static_cast<int>(y2) != 0) continue;
            if (x3 - static_cast<int>(x3) != 0) continue;
            if (y3 - static_cast<int>(y3) != 0) continue;
            if (s.find(make_pair((int)x2, (int)y2)) == s.end() || s.find(make_pair((int)x3, (int)y3)) == s.end()) continue;
            double d = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
            ans = max(ans, d * d / 2.0);
        }
    }
    std::cout << std::setprecision(15);
    cout << ans << endl;
    return 0;
}
