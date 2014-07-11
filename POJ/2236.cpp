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

double distance(int x0, int y0, int x1, int y1) {
    return hypot(x1-x0, y1-y0);
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

int main() {
    cin >> N >> d;
    int a, b;
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &cords[0][i], &cords[1][i]);
    }

    UF uf(N);

    char c, o; scanf("%c", &c);
    int n, j, k;
    while(scanf("%c", &o) != EOF) {
        if(o == 'O') {
            scanf("%d", &n); n--;
            if(!repaired[n]) {
                repaired[n] = true;
                for(int i = 0; i < N; i++) {
                    if(repaired[i]) {
                        double d0 = distance(cords[0][n], cords[1][n],
                                             cords[0][i], cords[1][i]);
                        if(d0 <= d) uf.unite(n, i);
                    }
                }
            }
        } else {
            scanf("%d %d", &j, &k); j--; k--;
            puts(uf.same(j, k) ? "SUCCESS" : "FAIL");
        }
        scanf("%c", &c);
    }

    return 0;
}
