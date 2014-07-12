// O(V^3)

// max(initial_d[i][j])*V^2 <= INF
// INF^2 <= MAX_INT
const int INF = (1<<30)-1;

//d[i][i] = 0, d[i][j] = INF if there isn't a edge between i and j
int d[MAX_V][MAX_V]

void warshall_floyd(int V) {
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
