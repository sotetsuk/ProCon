#include <iostream>
#include <vector>
using namespace std;

// O(E*log(V))

struct edge { int u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

vector<edge> es;
int V, E;

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

int kruskal() {
    sort(es.begin(), es.end(), comp);
    UF uf(V);
    int res = 0;
    for(int i = 0; i < E; i++) {
        edge e = es[i];
        if(!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main() {
    int c;
    while(cin >> V) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                cin >> c;
                if(i < j) es.push_back(edge(i, j, c));
            }
        }
    }
    cout << kruskal() << endl;
    return 0;
}
