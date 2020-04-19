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
#include <numeric>
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

struct Swap { ll v; int x; int y; };

int main() {
    int n, a;
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v.emplace_back(make_pair(i, a));
    }
    auto comp = [](Swap x, Swap y){ return x.v > y.v; };
    priority_queue<Swap, vector<Swap>, decltype(comp)> q(comp);
    vector<bool> used(n);
    bool updated = true;
    while (updated) {
        updated = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto x = v[i];
                auto y = v[j];
                auto i0 = x.first;
                auto j0 = y.first;
                auto A_i = x.second;
                auto A_j = y.second;
                auto diff = A_i * abs(j - i0) - A_i * abs(i - i0) + A_j * abs(i - j0) - A_j * abs(j - j0);
                if (diff <= 0) continue;
                q.push(Swap{diff, i, j});
                updated = true;
            }
        }
        for (int i = 0; i < n; ++i) used[i] = false;
        while (!q.empty()) {
            auto s = q.top(); q.pop();
            auto x = s.x;
            auto y = s.y;
            if (used[x]||used[y]) continue;
            swap(v[x], v[y]);
            used[x] = true;
            used[y] = true;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        auto i0 = v[i].first;
        auto A = v[i].second;
        ans += A * abs(i - i0);
    }
    cout << ans << endl;
    return 0;
}
