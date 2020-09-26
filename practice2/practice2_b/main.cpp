#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    int N, Q; cin >> N >> Q;
    atcoder::fenwick_tree<ll> fw(N);
    for (int i = 0; i < N; ++i) {
        int a; cin >> a; fw.add(i, a);
    }
    for (int i = 0; i < Q; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 0) fw.add(b, c);
        else cout << fw.sum(b, c) << endl;
    }
    return 0;
}
