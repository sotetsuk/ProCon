#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <map>

// namespace
using namespace std;

struct edge { int from, to, cost; };
vector<int> bellman_ford(int start, int num_vertex, const vector<edge> &edges) {
    vector<int> d(num_vertex, INT_MAX);
    d[start] = 0;
    while (true) {
        bool updated = false;
        // for (const auto &e: edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edge e = edges[i];
            if (d[e.from] != INT_MAX && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                updated = true;
            }
        }
        if (!updated) break;
    }
    return d;
}

vector<int> dijkstra(int start, int num_vertex, map<int, vector<edge>> &edges) {
    using P = pair<int, int>;
    // typedef pair<int, int> P;
    priority_queue<P, vector<P>, greater<>> q;
    vector<int> d(num_vertex, INT_MAX);
    d[start] = 0;
    q.push(P{0, start});
    while (!q.empty()) {
        P p = q.top(); q.pop();
        if (d[p.second] < p.first) continue;  // if this item is not the smallest distance to v
        for (const auto &e: edges[p.second]) {
        // for (int i = 0; i < edges[p.second].size(); ++i) {
        //     edge e = edges[p.second][i];
            if (d[e.from] != INT_MAX && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                q.push(P{d[e.to], e.to});
            }
        }
    }
    return d;
}

int main() {
    int v, e, s, from, to, cost;
    cin >> v >> e >> s;
    // vector<edge> es;
    map<int, vector<edge> > es;
    for (int i = 0; i < e; ++i) {
        cin >> from >> to >> cost;
        // es.push_back(edge{from, to, cost});
        es[from].push_back(edge{from, to, cost});
    }
    // vector<int> ans = bellman_ford(s, v, es);
    vector<int> ans = dijkstra(s, v, es);
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] != INT_MAX) cout << ans[i] << endl;
        else cout << "INF" << endl;
    }
    return 0;
}
