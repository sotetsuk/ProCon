#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

// namespace
using namespace std;

using P = pair<int, int>;
struct edge { int from, to, cost; };
// int prim(int num_vertex, map<int, vector<edge> > &edges) {
//     vector<bool> included(num_vertex, false);
//     priority_queue<P, vector<P>, greater<>> q;
//     q.push(P{0, 0});
//     int total_cost = 0;
//     while(!q.empty()) {
//         P p = q.top(); q.pop();
//         int cost = p.first; int v = p.second;
//         if (included[v]) continue;
//         included[v] = true;
//         total_cost += cost;
//         for (const auto &e: edges[v]) q.push(P{e.cost, e.to});
//     }
//     return total_cost;
// }

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

int kruskal(int num_vertex, vector<edge> &edges) {
    auto comp = [](edge e1, edge e2){ return e1.cost < e2.cost; };
    sort(edges.begin(), edges.end(), comp);
    UnionFind uf(num_vertex);
    int total_cost = 0;
    for (const auto &e : edges) {
        if (uf.same(e.from, e.to)) continue;
        uf.unite(e.from, e.to);
        total_cost += e.cost;
    }
    return total_cost;
}

int main() {
    int v, e, from, to, cost;
    vector<edge> edges;
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        cin >> from >> to >> cost;
        edges.push_back(edge{from, to, cost});
    }
    int total_cost = kruskal(v, edges);
    cout << total_cost << endl;
    return 0;
}
