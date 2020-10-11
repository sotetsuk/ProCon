#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::vector<ll> a(4); for (int i = 0; i < 4; ++i) cin >> a[i];
    for (int i = 1; i < (1<<4); ++i) {
        ll s = 0;
        for (int j = 0; j < 4; ++j) {
            if ((1<<j) & i) s += a[j];
            else s -= a[j];
        }
        if (s == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
