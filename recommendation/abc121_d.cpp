#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) {
    ll ret = ((x + 1) / 2) % 2;
    if (x % 2 == 0) return ret^x;
    else return ret;
}

int main() {
    ll A, B; cin >> A >> B;
    if (A > 0) cout << (ll)(f(B) ^ f(A-1)) << endl;
    else cout << f(B) << endl;
    return 0;
}
