#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll N, M; cin >> N >> M;
    atcoder::dsu d(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        d.merge(a, b);
    }
    cout << d.groups().size() - 1 << endl;
    return 0;
}
