#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int R, C, D; cin >> R >> C >> D;
    vector<vector<int>> A(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> A[i][j];
        }
    }
    int ans = INT_MIN;
    for (int d = D % 2; d <= D; d += 2) {
        for (int j = 0; j <= d; ++j) {
            int i = d - j;
            if (i >= R || j >= C) continue;
            ans = max(ans, A[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
