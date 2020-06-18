#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    if (N == 1) {
        cout << "Yes" << endl;
        cout << 2 << endl;
        cout << "1 1" << endl;
        cout << "1 1" << endl;
        return 0;
    }
    // 6
    // 12 = 4 * 3
    int M = -1;
    for (int i = 1; i <= N; ++i) {
        if (i * (i - 1) == 2 * N) {
            M = i;
            break;
        }
    }
    if (M == -1) {
        cout << "No" << endl;
        return 0;
    }
    vector<vector<int>> v(M, vector<int>(M-1, 0));
    int c = 1;
    for (int k = M - 1; k > 0; --k) {
        for (int l = 0; l < k; ++l) {
            int i0 = M - k - 1;
            int j0 = M - 1 - k + l;
            int i1 = M - k + l;
            int j1 = M - 1 - k;
            v[i0][j0] = c;
            v[i1][j1] = c;
            ++c;
        }
    }
    cout << "Yes" << endl;
    cout << v.size() << endl;
    for (const auto &row: v) {
        cout << row.size();
        for (const auto &e: row) {
            cout << " " << e;
        }
        cout << endl;
    }
    return 0;
}
