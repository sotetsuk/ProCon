#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll X, K, D; cin >> X >> K >> D;
    X = abs(X);
    ll m = X / D;
    if (K <= m) {
        cout << X - D * K << endl;
    } else {
        X -= m * D;
        K -= m;
        if (K % 2 == 0) {
            cout << X << endl;
        } else {
            cout << min({abs(X + D), abs(X - D)}) << endl;
        }
    }
    return 0;
}
