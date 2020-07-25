#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> a(N); for (int i = 0; i < N; ++i) cin >> a[i];
    int ans = INT_MIN;
    for (int i = 0; i < N; ++i) {
        int opp = INT_MIN;
        int self = INT_MIN;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            int self_p = 0;
            int opp_p = 0;
            int cnt = 0;
            for (int k = min(i, j); k <= max(i, j); ++k) {
                if (cnt % 2 == 0) self_p += a[k];
                else opp_p += a[k];
                ++cnt;
            }
            // cout << i << " " << j << " " << opp_p << " " << self_p << endl;
            if (opp_p > opp) {
                opp = opp_p;
                self = self_p;
            }
        }
        ans = max(ans, self);
    }
    cout << ans << endl;
    return 0;
}
