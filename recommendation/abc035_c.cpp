#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> s(N + 1);
    string ans;
    for (int i = 0; i < Q; ++i) {
        int l, r; cin >> l >> r; --l; --r;
        s[l]++;
        s[r+1]++;
    }
    for (int i = 0; i < N; ++i) s[i+1] += s[i];
    for (int i = 0; i < N; ++i) ans += s[i] % 2 ? "1" : "0";
    cout << ans << endl;
    return 0;
}
