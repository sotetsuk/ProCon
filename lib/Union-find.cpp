struct UnionFind{
    vector<int> par;
    vector<int> rank;  // height of tree
	UnionFind(int m) : par(m), rank(m) {
		for(int i = 0; i < m; i++){
			par[i] = i;
			rank[i] = 0;
		}
	}
	int root(int x) {
		return x == par[x] ? x : par[x] = root(par[x]);
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	void unite(int x, int y) {
		if(same(x, y)) return;
		if(rank[x] < rank[y]) {
		    par[root(x)] = root(y);  // make y above
		} else {
		    par[root(y)] = par[root(x)];
		    if(rank[x] == rank[y]) ++rank[x];
		}
	}
};
