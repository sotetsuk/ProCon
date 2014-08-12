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
#include <sstream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

const int MAX_N = 14, MAX_M = 100000;
int n, m;

string c[MAX_N+5];
bool a[MAX_N];

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

bool str_same(int i, int j) {
    for(int k = 0; k < m; k++) {
        if(c[i][k] != c[j][k]) {
            if(c[i][k] != '*' && c[j][k] != '*') return false;
            if(c[i][k] != '*' && c[j][k] == '*') c[j][k] = c[i][k];
            if(c[i][k] == '*' && c[j][k] != '*') c[i][k] = c[j][k];
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    UF uf(n);

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(str_same(i, uf.find(j))) {
                uf.unite(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        a[uf.find(i)] = true;;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}
