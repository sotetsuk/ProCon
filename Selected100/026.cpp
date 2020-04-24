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
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>

///////////////////////////////////////////////////////////////
// namespace
///////////////////////////////////////////////////////////////
using namespace std;
// namespace mp = boost::multiprecision;

///////////////////////////////////////////////////////////////
// types
///////////////////////////////////////////////////////////////
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// using mpi = mp::cpp_int;
// using mpf = mp::number<mp::cpp_dec_float<1024>>;

///////////////////////////////////////////////////////////////
// mod https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
///////////////////////////////////////////////////////////////
// ll MOD = 1000000007;
// ll mod(long long val) {
//     long long res = val % MOD;
//     if (res < 0) res += MOD;
//     return res;
// }
// ll modinv(ll a) {
//     ll b = MOD, u = 1, v = 0;
//     while (b) {
//         ll t = a / b;
//         a -= t * b; swap(a, b);
//         u -= t * v; swap(u, v);
//     }
//     u %= MOD;
//     if (u < 0) u += MOD;
//     return u;
// }

int N, Q;

map<int, vector<int>> m;
ll arr[200005];
ll ans[200005];
queue<pii> q;

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b; --a; --b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    memset(arr, 0, sizeof(arr));
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < Q; ++i) {
        ll p, x;
        cin >> p >> x; --p;
        arr[p] += x;
    }

    q.push(make_pair(0, 0));
    while (!q.empty()) {
        ll node = q.front().first;
        ll s = q.front().second;
        q.pop();
        // cout << "queue: " << node << " " << s << endl;
        s += arr[node];
        ans[node] = s;
        for (auto &next : m[node]) {
            // cout << "  next: " << next << endl;
            if (ans[next] != -1) continue;
            q.push(make_pair(next, s));
        }
    }
    for (int i = 0; i < N; ++i) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
