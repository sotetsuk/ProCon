#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int op(int x, int y) { return max(x, y); }
int e() { return 0; }
int a;
bool f(int elm) { return elm < a; }

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N); for (int i = 0; i < N; ++i) cin >> A[i];
    atcoder::segtree<int, op, e> st(A);
    for (int i = 0; i < Q; ++i) {
        int T, X, V; cin >> T >> X >> V;
        if (T == 1) {
            --X;
            st.set(X, V);
        } else if (T == 2) {
            int L = X - 1;
            int R = V;
            cout << st.prod(L, R) << endl;
        } else {
            --X;
            a = V;
            int r = st.max_right<f>(X);
            cout << r + 1 << endl;
        }
    }
    return 0;
}
