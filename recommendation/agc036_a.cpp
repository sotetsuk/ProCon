#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll S; cin >> S;
    ll x1 = 1;
    ll y1 = 1e9;
    ll x2 = (S + (y1 - 1)) / y1;
    ll y2 = (y1 - 1) - (S + (y1 - 1)) % y1;
    cout << "0 0 ";
    cout << x1 << " " << y1 << " ";
    cout << x2 << " " << y2 << endl;
    // cout << abs(x1 * y2 - x2 * y1) << endl;
    return 0;
}
