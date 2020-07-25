#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    vector<ll> A(N); for (int i = 0; i < N; ++i) cin >> A[i];
    ll m = 1000;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] < A[i + 1]) {
            m += (A[i + 1] - A[i]) * (m / A[i]);
        }
    }
    cout << m << endl;
    return 0;
}
