#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char, int> P;

const int MAX_N = 100000, MAX_Q = 100000;
int N, Q;

int par[MAX_N+5];
int par2[MAX_N+5];

void init(int N) {
    for(int i = 0; i <= N; i++) {
        par[i] = i;
        par2[i] = i;
    }
}

int find(int n) {
    if(par[n] == n) return n;
    par[n] = find(par[n]);
    return par[n];
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    // x is above
    if(same(x, y)) return;
    par[y] = x;
}

void show_par() {
    for(int i = 1; i <= N; i++) {
        cout << i << ": " << par[i] << ", ";
    }
    cout << endl;
}

int main() {
    while(true) {
        // input
        cin >> N >> Q;
        if(!N && !Q) break;
        init(N);
        int p;
        for(int i = 2; i <= N; i++) {
            cin >> p;
            par[i] = p;
            par2[i] = p;
        }
        vector<P> v;
        char c;
        int t;
        for(int i = 0; i < Q; i++) {
            cin >> c >> t;
            if(c == 'M') {
                par[t] = t;
            }
            P q;
            q.first = c;
            q.second = t;
            v.push_back(q);
        }

        // solve
        long long int ans = 0;
        show_par();
        for(int i = v.size()-1; i >= 0; i--) {
            if(v[i].first == 'M') {
                unite(par2[v[i].second], v[i].second);
            } else {
                ans += find(v[i].second);
            }
            cout << v[i].first << " " << v[i].second << endl;
            show_par();
        }
        cout << ans << endl;
    }
    return 0;
}
