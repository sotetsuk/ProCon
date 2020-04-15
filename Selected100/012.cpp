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

const int N = 12;
int arr[N][N];

int main() {
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arr[i][j] = 0;
            if (i == j) arr[i][j] = 1;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        arr[x-1][y-1] = 1;
        arr[y-1][x-1] = 1;
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        vector<int> v;
        for (int i = 0; i < N; ++i) if (bit & (1 << i)) v.push_back(i);
        bool flag = true;
        for (const auto &e1 : v) {
            for (const auto &e2 : v) {
                if (arr[e1][e2] != 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) ans = max(ans, static_cast<int>(v.size()));
    }
    cout << ans << endl;

    return 0;
}
