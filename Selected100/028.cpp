#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int n, u, k; cin >> n;
    vector<vector<int> > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> u >> k;
        vector<int> v0(k);
        for (int j = 0; j < k; ++j) {
            cin >> v0[j];
            --v0[j];
        }
        v[u-1] = v0;
    }
    queue<pair<int, int> > q;
    vector<bool> visited(n, false);
    q.push(make_pair(0, 0));
    visited[0] = true;
    vector<int> ans(n, -1);
    ans[0] = 0;
    while(!q.empty()) {
        pair<int, int> x = q.front(); q.pop();
        int cnt = x.second + 1;
        for (int i = 0; i < v[x.first].size(); ++i) {
            int j = v[x.first][i];
            if (!visited[j]) {
                q.push(make_pair(j, cnt));
                visited[j] = true;
                ans[j] = cnt;
            }
        }
    }
    for (int i = 0; i < n; ++i) cout << i + 1 << " " << ans[i] << endl;
    return 0;
}
