#include <bits/stdc++.h>
using namespace std;

// https://twitter.com/chokudai/status/1280403664251703296?s=20
// ちゃんと測ってはないけど20分はかからなかった

int main() {
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<bool>> solved(N+1, vector<bool>(M+1));
    vector<int> num_solver(M+1);
    for (int i = 0; i < Q; ++i) {
        int query_type; cin >> query_type;
        int n; cin >> n;
        if (query_type == 1) {
            int score = 0;
            for (int j = 0; j <= M; ++j) {
                if (!solved[n][j]) continue;
                score += N - num_solver[j];
            }
            cout << score << endl;
        } else {
            int m; cin >> m;
            solved[n][m] = true;
            num_solver[m]++;
        }
    }
    return 0;
}
