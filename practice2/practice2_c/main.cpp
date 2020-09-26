#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b, n, m; cin >> n >> m >> a >> b;
        cout << atcoder::floor_sum(n, m, a, b) << endl;
    }
    return 0;
}
