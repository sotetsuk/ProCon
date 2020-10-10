#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_at(char c) {
    return c == 'A' || c == 'T';
}

bool is_ac(char c) {
    return c == 'A' || c == 'C';
}

int main() {
    ll N; cin >> N;
    string S; cin >> S;
    vector<int> a(N + 1), t(N + 1), c(N + 1), g(N + 1);
    for (int i = 0; i < S.size(); ++i) {
        a[i + 1] = a[i];
        t[i + 1] = t[i];
        c[i + 1] = c[i];
        g[i + 1] = g[i];
        if (S[i] == 'A') a[i + 1]++;
        if (S[i] == 'T') t[i + 1]++;
        if (S[i] == 'C') c[i + 1]++;
        if (S[i] == 'G') g[i + 1]++;
    }
    ll ans = 0;
    for (int i = 0; i < S.size(); ++i) {
        for (int j = i + 2; j <= S.size(); ++j) {
            // cout << i << " " << j << " " << a[j] - a[i] << " " << t[j] - t[i] << " " << c[j] - c[i] << " " << g[j] - g[i] << endl;
            if (a[j] - a[i] == t[j] - t[i] &&
                c[j] - c[i] == g[j] - g[i]) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
