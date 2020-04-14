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

// consts
int MOD = 1000000007;  // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a


int main() {
    int m, n, x, y;
    vector<pii> v0;
    vector<pii> v1;
    set<pii> s;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        v0.emplace_back(make_pair(x, y));
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        v1.emplace_back(make_pair(x, y));
        s.insert(make_pair(x, y));
    }
    // cout << "debug " << s.size() << endl;
    for (int i = 0; i < n; ++i) {
        int x0 = v1[i].first;
        int y0 = v1[i].second;
        bool flag = true;
        for (int j = 0; j < m; ++j) {
            int xt = x0 + v0[j].first - v0[0].first;
            int yt = y0 + v0[j].second- v0[0].second;
            // cout << "deubg: " << xt << " " << yt << endl;
            if (s.find(make_pair(xt, yt)) == s.end()) {
                // cout << "false" << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << x0 - v0[0].first << " " << y0 - v0[0].second << endl;
            return 0;
        }
    }
    return 0;
}
