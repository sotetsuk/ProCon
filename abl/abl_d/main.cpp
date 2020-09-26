#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int op(int x, int y) { return max(x, y); }
int e() { return 0; }

int main() {
    // dp[i][j] = i番目までみたとき、最後に見た値がjのときの最大値（0, ..., i）
    // dp[i][j] = max({dp[i-1][j-K], ... dp[i-1][j+K]}) + 1
    // dp[j] = max({dp[j-K], ..., dp[j+K]}) + 1
    const int MAX_A = 300005;
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    atcoder::segtree<int, op, e> st(MAX_A);
    for (int i = 0; i < N; ++i) {
        st.set(A[i], st.prod(max(0, A[i] - K), min(MAX_A - 1, A[i] + K + 1)) + 1);
    }
    cout << st.all_prod() << endl;
    return 0;
}
