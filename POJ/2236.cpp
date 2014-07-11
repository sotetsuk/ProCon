#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 1001;
int N, d;
bool repaired[MAX_N];
int cords[2][MAX_N];
int par[MAX_N];
int uf_rank[MAX_N];
double dis[MAX_N][MAX_N];

double distance(int x0, int y0, int x1, int y1) {
    return hypot(x1-x0, y1-y0);
}

void init(int m) {
    for(int i = 0; i < m; i++){
        par[i] = i;
        uf_rank[i] = 0;
    }
}

int find(int x){
    return x != par[x] ? par[x] = find(par[x]) : x;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    // y is above
    if(uf_rank[x] < uf_rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if(uf_rank[x] == uf_rank[y]) uf_rank[x]++;
    }
}

int main() {
    cin >> N >> d;
    int a, b;
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &cords[0][i], &cords[1][i]);
    }

    init(N);

    char c, o; scanf("%c", &c);
    int n, j, k;
    while(scanf("%c", &o) != EOF) {
        if(o == 'O') {
            scanf("%d", &n); n--;
            if(!repaired[n]) {
                repaired[n] = true;
                for(int i = 0; i < N; i++) {
                    if(repaired[i]) {
                        if(!dis[n][i]) {
                            double d0 = distance(cords[0][n], cords[1][n],
                                                 cords[0][i], cords[1][i]);
                            dis[n][i] = d0; dis[i][n] = d0;
                        }
                        if(dis[n][i] <= d) unite(n, i);
                    }
                }
            }
        } else {
            scanf("%d %d", &j, &k); j--; k--;
            puts(same(j, k) ? "SUCCESS" : "FAIL");
        }
        scanf("%c", &c);
    }

    return 0;
}
