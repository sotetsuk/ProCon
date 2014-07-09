#include <iostream>
using namespace std;

const int INF = 100005;
const int MAX_V = 105;
int V;

// O(V^2)
int cost[MAX_V][MAX_V]; // the weight of edge from u to v

int prim(int V, int (*cost)[MAX_V]) {
    // V: num of vertex

    int mincost[V]; // distance from tree X
    bool used[V]; // true if in tree X

    for(int i = 0; i < V; i++) {
        mincost[i] = INF;
        used[i] = false;
    }

    mincost[0] = 0;
    int res = 0;

    while(true) {
        int v = -1;
        for(int u = 0; u < V; u++) {
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }

        if (v == -1) break;
        used[v] = true;
        res += mincost[v];

        for(int u = 0; u < V; u++) {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }

    return res;
}

int main() {
    while(cin >> V) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                cin >> cost[i][j];
            }
        }

        int ans = prim(V, cost);
        cout << ans << endl;
    }

    return 0;
}
