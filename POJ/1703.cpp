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
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

const int MAX_N = 100000;

int T, N, M;
int diff[MAX_N];

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

void solve() {
    scanf("%d %d", &N, &M);
    memset(diff, -1, sizeof(diff));
    UF uf(2*N);
    char o; int a, b;
    for(int i = 0; i < M; i++) {
        scanf("%c", &o); scanf("%c %d %d", &o, &a, &b); a--; b--;
        if(o == 'D') {
            uf.unite(a, b+N);
            uf.unite(a+N, b);
        } else {
            if(uf.same(a, b)) {
                cout << "In the same gang." << endl;
            } else if(uf.same(a, b+N)) {
                cout << "In different gangs." << endl;
            } else {
                cout << "Not sure yet." << endl;
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
