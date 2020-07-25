#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N); for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - K; ++i) {
        int j = i + K;
        if (A[i] < A[j]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
