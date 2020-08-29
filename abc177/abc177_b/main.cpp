#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s, t; cin >> s >> t;
    int n = t.size();
    int m = 0;
    for (int i = 0; i < s.size(); ++i) {
        bool ok = true;
        int cnt = 0;
        for (int j = 0; j < t.size(); ++j) {
            if (i + j >= s.size()) {
                ok = false;
                break;
            }
            if (s[i + j] == t[j]) ++cnt;
        }
        if (ok) {
            m = max(m, cnt);
        }
    }
    cout << n - m << endl;
    return 0;
}
