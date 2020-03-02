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
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

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
            par[root(y)] = par[root(x)];
            if(rank[x] == rank[y]) ++rank[x];
        }
    }
};

int N, K, M, A, B, C, D;

int main() {
    cin >> N >> M >> K;
    vector<vector<int>> f(N+1);
    vector<vector<int>> b(N+1);
    UnionFind uf(N+1);
    for (int i = 0; i < M; ++i) {
        cin >> A >> B;
        uf.unite(A, B);
        f[A].push_back(B);
        f[B].push_back(A);
    }
    for (int i = 0; i < K; ++i) {
        cin >> C >> D;
        b[C].push_back(D);
        b[D].push_back(C);
    }

    unordered_map<int, int> sizes;
    for (int i = 1; i <= N; ++i) sizes[uf.root(i)]++;
    for (int i = 1; i <= N; ++i) {
        int ans = sizes[uf.root(i)] - 1;
        ans -= f[i].size();
        for (auto j : b[i]) if (uf.same(i, j)) --ans;
        cout << ans << " ";
    }

    return 0;
}
