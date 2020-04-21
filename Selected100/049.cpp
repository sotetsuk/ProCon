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
#include <bitset>
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
using pii = pair<int, int>;
using ll = long long int;
using ld = long double;
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

// V: number of nodes
// v: current node
// S: all visited nodes
// dp[S][v]: Minimum total cost from 0 to v through all node in S
// answer: dp[(1<<V)-1][0];
int tsp(int S, int v, int V, vector<vector<int>> &dist, vector<vector<int>> &dp) {
    if (S == 0) return v == 0 ? 0 : INT_MAX;
    if (dp[S][v] >= 0) return dp[S][v];
    int ret = INT_MAX;
    for (int u = 0; u < V; ++u) {
        if (!(S&(1<<u))) continue;
        int tmp = tsp(S&(~(1<<u)), u, V, dist, dp);
        if (tmp == INT_MAX || dist[u][v] == INT_MAX) continue;
        ret = min(ret, tmp + dist[u][v]);
    }
    return dp[S][v] = ret;
}


int main() {
    int V, E, s, t, d;
    cin >> V >> E;
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    for (int i = 0; i < E; ++i) {
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    vector<vector<int>> dp(1<<(V+2), vector<int>(V, -1));
    int ans = tsp((1<<V) - 1, 0, V, dist, dp);
    cout << ((ans != INT_MAX) ? ans : -1) << endl;
    return 0;
}
