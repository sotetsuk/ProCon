#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// for 1 ... N O(N)
// MAX_N = 2^(2e5)
//   f(MAX_N) < 2e5
//   f(2e5) < 31
//   f(31) < 8

int popcount(int x) {
    return __builtin_popcount(x);
}

int f(int x) {
    if (x == 0) return 0;
    return f(x % popcount(x)) + 1;
}

int main() {
    int N; cin >> N;
    string s; cin >> s;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) X[i] = s[i] - '0';
    int pc0 = accumulate(X.begin(), X.end(), 0);
    vector<int> ans(N);
    for(int b = 0; b < 2; ++b) {
        int pc = pc0;
        if (b == 0) ++pc; else --pc;
        if (pc <= 0) continue;
        int r0 = 0;
        for (int i = 0; i < N; ++i) {
            r0 = (r0 * 2) % pc;
            r0 = (r0 + X[i]) % pc;
        }
        int p = 1;
        for (int i = 0; i < N; ++i) {
            int ix = N - i - 1;
            if (X[ix] == b) {
                int r = r0;
                if (b == 0) {
                    r += p;
                    r %= pc;
                } else {
                    r -= p;
                    r = (r + pc) % pc;
                }
                ans[ix] = f(r) + 1;
            }
           p = (p * 2) % pc;
        }
    }
    for (int i = 0; i < N; ++i) cout << ans[i] << endl;
    return 0;
}
