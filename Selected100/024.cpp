#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(int curr, int &cnt, const vector<vector<int> > & v, vector<bool> &visited, map<int, vector<int> > &m) {
    if (visited[curr]) return;
    ++cnt;
    int d = cnt;
    visited[curr] = true;
    // cout << "Found : " << curr + 1 << " " << d << endl;
    for (int j = 0; j < v[curr].size(); ++j) {
        int e = v[curr][j];
        dfs(e, cnt, v, visited, m);
    }
    ++cnt;
    int f = cnt;
    m[curr] = {d, f};
    return;
}

int main() {
    int n, u, k;
    cin >> n;
    vector<vector<int> > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> u >> k;
        vector<int> v0(k);
        for (int j = 0; j < k; ++j) {
            cin >> v0[j];
            --v0[j];
        }
        v[u - 1] = v0;
    }
    vector<bool> visited(n, false);
    map<int, vector<int> > m;
    int cnt = 0;
    for (int i = 0; i < n; ++i) dfs(i, cnt, v, visited, m);
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " " << m[i][0] << " " << m[i][1] << endl;
    }
    return 0;
}
