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
    int r, c, t;
    cin >> r >> c;
    vector<vector<int>> v;
    for (int i = 0; i < r; ++i) {
        vector<int> v0;
        for (int j = 0; j < c; ++j) {
            cin >> t;
            v0.push_back(t);
        }
        v.push_back(v0);
    }

    int ans = 0;
    for (int bit = 0; bit < (1<<r); ++bit) {
        int x = 0;
        // cout << "===" << endl;
        // cout << bit << endl;
        // cout << "===" << endl;
        for (int col = 0; col < c; ++col) {
            int s = 0;
            for (int row = 0; row < r; ++row) {
                s += ((bit >> row) & 1) ^ v[row][col];
                // cout << "  " << (int)(((bit >> row) & 1) ^ v[row][col]) << endl;
            }
            x += max(s, r - s);
            // cout << "col = " << col << ", "<< max(s, r- s) << endl;
        }
        // cout << "x = " << x << endl;
        ans = max(ans, x);
    }
    cout << ans << endl;

    return 0;
}
