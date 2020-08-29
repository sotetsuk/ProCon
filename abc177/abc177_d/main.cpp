#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind{
    vector<int> par;
    vector<int> rank;  // height of tree
    UnionFind(int m) : par(m), rank(m) {
        for(int i = 0; i < m; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    int root(int x) {
        return x == par[x] ? x : par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    void unite(int x, int y) {
        if(same(x, y)) return;
        if(rank[x] < rank[y]) {
            par[root(x)] = root(y);  // make y above
        } else {
            par[root(y)] = root(x);
            if(rank[x] == rank[y]) ++rank[x];
        }
    }
};

int main() {
    int N, M; cin >> N >> M;
    auto uf = UnionFind(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        uf.unite(a, b);
    }
    unordered_map<int, int> root_size;
    for (int n = 0; n < N; ++n) {
        root_size[uf.root(n)]++;
    }
    int ans = 0;
    for (const auto& [k, v]: root_size) {
        ans = max(ans, v);
    }
    cout << ans << endl;
    return 0;
}
