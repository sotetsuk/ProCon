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

const int MAX_E = 10000;
const int MAX_V = 1000;
const int INF = 10000;

struct edge { int from, to, cost; };

edge es[2 * MAX_E+10];

ll d[MAX_V+10];
ll d_s[MAX_V+10];
int V, E, s, t;

void shortest_path(int s) {
    for(int i = 0; i <= V; i++) {
        d[i] = INF;
    }

    d[s] = 0;
    while(true) {
        bool update = false;
        for (int i = 0; i < 2*E; i++) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}

int main() {
    cin >> V >> E;
    cin >> s >> t;
    int f, t, c;
    for(int i = 0; i < E; i++) {
        cin >> f >> t >> c;
        edge e;
        e.from = f;
        e.to = t;
        e.cost = c;
        es[i] = e;
        edge e2;
        e2.from = t;
        e2.to = f;
        e2.cost = c;
        es[i+E] = e2;
    }

    shortest_path(s);
    for(int i = 1; i <= V; i++) {
        d_s[i] = d[i];
    }
    shortest_path(t);

    bool flag = true;
    for(int i = 1; i <= V; i++) {
        // cout << d_s[i] << ", " <<  d[i] << endl;//
        if(d_s[i] == d[i] && d[i] != INF && i != s && i != t) {
            cout << i << endl;
            flag = false;
            break;
        }
    }
    if(flag) cout << -1 << endl;

    return 0;
}
