#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    vector<ll> A(N); for (ll i = 0; i < N; ++i) cin >> A[i];
    for (ll i = 0; i < N; ++i) A[i] = A[i] - (i + 1);
    sort(A.begin(), A.end());
    vector <ll> candidates;
    ll s_min = 2e18;
    for (ll b = A[N/2]; b < A[N/2] + 1; ++b) {
        ll s = 0;
        for (ll i = 0; i < N; ++i) {
            s += abs(b - A[i]);
        }
        if (s < s_min) {
            s_min = s;
        }
    }
    cout << s_min << endl;
    return 0;
}
