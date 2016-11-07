// O(E*log(V))
struct Edge {
    Edge(int a, int b, int c) {
        u = a; v = b; cost = c;
    }
    int u, v, cost;
};

bool comp(const Edge& e1, const Edge& e2) {
    return e1.cost < e2.cost;
}

struct UF{
    vector<int> par;
    UF(int m) : par(m){
        for(int i = 0; i < m; i++){
            par[i] = i;
        }
    }
    int find(int x){
        return x != par[x] ? par[x] = find(par[x]) : x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void unite(int x, int y){
        // y is above
        if(!same(x, y)) par[find(x)] = find(y);
    }
};

int kruskal(int V, vector<Edge>& es) {
    sort(es.begin(), es.end(), comp);
    UF uf(V);
    int res = 0;
    for(int i = 0; i < es.size(); i++) {
        Edge e = es[i];
        if(!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

vector<Edge> es;
int V;
