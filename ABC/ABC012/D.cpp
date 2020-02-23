#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

const int MAX_N = 300;
const int INF = (1<<30)-1;
// const int INF = MAX_N*MAX_N*1000;

int N, M;
int d[MAX_N][MAX_N];

void warshaint_floyd(int V) {
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    for(int i = 0; i < MAX_N; i++) {
        for(int j = 0; j < MAX_N; j++) {
            d[i][j] = INF;
            if(i == j) d[i][j] = 0;
        }
    }

    cin >> N >> M;
    int a, b, t;
    for(int i = 0; i < M; i++) {
        cin >> a >> b >> t; a--; b--;
        d[a][b] = t;
        d[b][a] = t;
    }

    warshaint_floyd(N);

    int ans = (1<<31)-1;
    for(int i = 0; i < N; i++) {
        int m = 0;
        for(int j = 0; j < N; j++) {
            m = max(m, d[i][j]);
        }
        ans = min(m, ans);
    }

    cout << ans << endl;
    return 0;
}
