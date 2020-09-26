#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using modint = atcoder::modint998244353;
using mint = atcoder::modint;


int main() {
    int N, Q; cin >> N >> Q;
    modint x(0);
    modint b(1);
    for (int i = 0; i < N; ++i) {
        x += b;
        b *= 10;
    }
    cout << x.val() << endl;
    for (int i = 0; i < Q; ++i) {
        int l, r, d; cin >> l >> r >> d;
        cout << (modint(d) * modint(10).pow(r - 1)).val() << endl;
        cout << (modint(d) * modint(10).pow(l - 1)).val() << endl;
        cout << (x - (x * modint(10).pow(r).inv())).val() << endl;
        cout << (x - (x * modint(10).pow(l).inv())).val() << endl;

        x += modint(d) * modint(10).pow(r - 1);
        x -= modint(d) * modint(10).pow(l - 1);
        x -= x - (x * modint(10).pow(r).inv());
        x += x - (x * modint(10).pow(l).inv());
        // cout << x.val() << endl;
    }
    return 0;
}
