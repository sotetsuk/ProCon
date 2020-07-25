#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dfs(ll k, ll N, ll bits) {
    if (k > N) return 0;
    ll ret = bits == 7 ? 1 : 0;
    for (int i = 0; i < 3; ++i)
        ret += dfs(k * 10 + vector<int>{3, 5, 7}[i], N, 1<<i|bits);
    return ret;
}

int main() {
    ll N; cin >> N;
    cout << dfs(0, N, 0) << endl;
    return 0;
}
