#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll ans = max({a * c, a * d, b * c, b * d});
    cout << ans << endl;
    return 0;
}
