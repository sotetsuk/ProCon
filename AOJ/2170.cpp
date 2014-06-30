#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<char, int> P;

const int MAX_N = 100000;
const int MAX_Q = 100000;
int N, Q;
int p[MAX_N+5];
bool M[MAX_N+5];
int uf_par[MAX_N+5];
int uf_rank[MAX_N+5];
int mark[MAX_N+5];

void init(int n) {
    for(int i = 0; i < N; i++) {
        uf_par[i] = i;
        uf_rank[i] = 0;
        mark[i] = i;
        p[i] = 0;
        M[i] = false;
    }
}

int find(int x) {
    if (uf_par[x] == x) {
        return x;
    } else {
        return uf_par[x] = find(uf_par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(uf_rank[x] < uf_rank[y]) {
        uf_par[x] = y;
        mark[y] = mark[x];
    } else {
        uf_par[y] = x;
        if(uf_rank[x] == uf_rank[y]) uf_rank[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void debug() {
    for(int i = 0; i < N; i++) {
        cout << i << ": " << mark[i] << ": " << find(i) << ": " << mark[find(i)] << endl;
    }
}

int main() {
    while(true) {
        cin >> N >> Q;
        if(!N && !Q) break;

        init(N);
        for(int i = 1; i < N; i++) {
            cin >> p[i];
            p[i]--;
        }
        vector<P> query;
        char qm;
        int num;
        for(int i = 0; i < Q; i++) {
            cin >> qm >> num;
            num--;
            if(qm == 'M') {
                M[num] = true;
            }
            query.push_back(P(qm, num));
        }

        for(int i = 0; i < N; i++) {
            if(!M[i]) {
                // cout << "unite " << p[i] << ": " << i << endl;
                // cout << M[i] << endl;
                unite(p[i], i);
                // debug();
            }
        }

        // cout << "====" << endl;
        long long int count = 0;
        for(int i = query.size()-1; i >= 0; i--) {
            int n = query[i].second;
            if(query[i].first == 'M') {
                // cout << "unite " << p[n] << ": " << n << endl;
                unite(p[n], n);
                // debug();
            } else {
                count += mark[find(n)] + 1;
                // cout << "n: " << n << " count += " << mark[find(n)] << endl;
            }
        }
        cout << count << endl;
    }
    return 0;
}
