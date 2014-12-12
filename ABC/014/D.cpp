#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

const int MAX_V = 100000 + 10;
const int MAX_LOG_V = 20;

int N, Q, x, y;

// 全ての2点間のLCAを求める
vector<int> G[MAX_V]; // グラフの隣接リスト表現
int root = 0; // 根ノードの番号

int parent[MAX_LOG_V][MAX_V]; // 親を2^k回遡って到達する頂点（根を通り過ぎる場合は-1とする)
int depth[MAX_V]; // 根からの深さ

void dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for(int i = 0; i < G[v].size(); i++) {
        if(G[v][i] != p) dfs(G[v][i], v, d + 1);
    }
}

// 初期化
void init(int V) {
    // parent[0]とdepthを初期化する
    dfs(root, -1, 0);
    // parentを初期化する
    for(int k = 0; k + 1 < MAX_LOG_V; k++) {
        for(int v = 0; v < V; v++) {
            if(parent[k][v] < 0) parent[k + 1][v] = -1;
            else parent[k + 1][v] = parent[k][parent[k][v]];
        }
    }
}

// uとvのLCAを求める
int lca(int u, int v) {
    // uとvの深さが同じになるまで親をたどる
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 0; k < MAX_LOG_V; k++) {
        if((depth[v] - depth[u]) >> k & 1) {
            v = parent[k][v];
        }
    }
    if(u == v) return v;
    for(int k = MAX_LOG_V - 1; k >= 0; k--) {
        if(parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int main() {
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        cin >> x >> y; x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    init(N);

    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> x >> y;
        x--; y--;
        cout << depth[x] + depth[y] - 2 * depth[lca(x, y)] + 1 << endl;
    }

    return 0;
}
