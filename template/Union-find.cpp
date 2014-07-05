// without rank
// ex) KUPC2014:C
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
