#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

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

const int MAX_N = 200, MAX_M = 200, MAX_Q = 200;
int N, M, Q;
int c[MAX_N], d[MAX_M];

int main() {
    cin >> N >> M >> Q;

    UF uf(N + M);

    for(int i = 0; i < Q; i++) {
        cin >> c[i] >> d[i];
        c[i]--; d[i]--;
        uf.unite(c[i], N + d[i]);
    }

    int ans = 0;
    for(int i = 1; i < N * M + 10; i++) {
        int n = (i-1) % N;
        int m = (i-1) % M;
        if(!uf.same(n, N + m)) ans = i;
        uf.unite(n, N + m);
    }
    cout << ans << endl;
}
