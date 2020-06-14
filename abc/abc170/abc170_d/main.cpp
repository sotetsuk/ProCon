#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector< int64_t > divisor(int64_t n) {
    vector< int64_t > ret;
    for(int64_t i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int main() {
    int n; cin >> n;
    vector<int> A(n);
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        m[A[i]]++;
    }
    int ans = 0;
    for (const auto &a: A) {
        auto d = divisor(a);
        bool ok = true;
        if (m[a] != 1) continue;
        for (const auto &p: d) {
            if (m.find(p) != m.end()) {
                if (p != a) ok = false;
                break;
            }
        }
        if (ok) ++ans;
    }
    cout << ans << endl;
    return 0;
}
