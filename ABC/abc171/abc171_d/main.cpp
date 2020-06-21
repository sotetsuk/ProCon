#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    unordered_map<ll, ll> m;
    ll s = 0;
    for (int i = 0; i < N; ++i) {
        ll a; cin >> a; m[a]++;
        s += a;
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        ll b, c; cin >> b >> c;
        s += (c - b) * m[b];
        m[c] += m[b];
        m[b] = 0;
        cout << s << endl;
    }
    return 0;
}
