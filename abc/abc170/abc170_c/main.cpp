#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x, n; cin >> x >> n;
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        int p; cin >> p; s.insert(p);
    }
    int m = INT_MAX;
    int ans = INT_MAX;
    for (int i = 101; i >= 0; --i) {
        if (s.find(i) != s.end()) continue;
        if (abs(x - i) <= m) {
            m = abs(x - i);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
