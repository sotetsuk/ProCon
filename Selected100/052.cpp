#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int N, M;
unordered_map<int, int> memo;
vector<vector<int>> s;

int dfs(int S) {
    if (S == 0) return 0;
    if (memo.find(S) != memo.end()) return memo[S];
    int ret = INF;
    int b = 0;
    for (int m = 0; m < M; ++m) if (1<<m&S) b += s[m].back();
    for (int m = 0; m < M; ++m) {
        if (!(1<<m&S)) continue;
        int a = b - s[m].back();
        ret = min(ret, dfs(S&~(1<<m)) + (b - a) - (s[m][b] - s[m][a]));
    }
    return memo[S] = ret;
}

int main() {
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i]; v[i]--;
    }
    s = vector<vector<int>>(M, vector<int>(N+1, 0));
    for (int m = 0; m < M; ++m) {
        for (int n = 0; n < N; ++n) {
            s[m][n+1] = s[m][n] + (v[n] == m ? 1 : 0);
        }
    }
    cout << dfs((1<<M)-1) << endl;
}
