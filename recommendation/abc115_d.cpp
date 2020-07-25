#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> a = {1};
vector<ll> p = {1};

ll dfs(ll N, ll X) {
    if (X == 0) return 0;
    if (N == 0) return 1;
    if (X <= 1 + a[N - 1]) return dfs(N - 1, X - 1);
    else return p[N - 1] + 1 + dfs(N - 1, X - a[N - 1] - 2);
}

int main() {
    ll N, X; cin >> N >> X;
    a.resize(N + 1);
    p.resize(N + 1);
    for (int i = 0; i < N; ++i) {
        a[i+1] = 2 * a[i] + 3;
        p[i+1] = 2 * p[i] + 1;
    }
    cout << dfs(N, X) << endl;
    return 0;
}
