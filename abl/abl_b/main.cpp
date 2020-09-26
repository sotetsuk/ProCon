#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    for (ll x : {a, b, c, d}) {
        if (a <= x && x <= b && c <= x && x <= d) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
