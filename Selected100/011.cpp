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
    int n, m, t, s;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int k = 0; k < m; ++k) {
        cin >> t;
        vector<int> v0;
        for (int i = 0; i < t; ++i) {
            cin >> s;
            v0.push_back(s - 1);
        }
        v.push_back(v0);
    }
    vector<int> p;
    for (int k = 0; k < m; ++k) {
        cin >> t;
        p.push_back(t);
    }

    int ans = 0;
    for (int bit = 0; bit < (1<<n); ++bit) {
        bool flag = true;
        for (int k = 0; k < m; ++k) {
            int c = 0;
            for (auto e: v[k]) if (bit & (1 << e)) ++c;
            if (c % 2 != p[k]) {
                flag = false;
                break;
            }
        }
        if (flag) ++ans;
    }
    cout << ans << endl;

    return 0;
}
