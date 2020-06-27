#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<ll> v(N+1);
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            v[j]++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += i * v[i];
    }
    cout << ans << endl;
}

