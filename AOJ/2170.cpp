#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef pair<char, int> P;

const int MAX_N = 100000, MAX_Q = 100000;
int N, Q;

int par[MAX_N+5];
int par2[MAX_N+5];
bool marked[MAX_N+5];

stack<P> s;

void init(int N) {
    for(int i = 0; i <= N; i++) {
        par[i] = i;
        par2[i] = i;
        marked[i] = false;
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
        char c;
        int t;
        for(int i = 0; i < Q; i++) {
            cin >> c >> t;
            if(c == 'M') {
                if(marked[t]) continue;
                marked[t] = true;
                par[t] = t;
            }
            P q;
            q.first = c;
            q.second = t;
            s.push(q);
        }

        // solve
        long long int ans = 0;
        while(!s.empty()) {
            P q = s.top(); s.pop();
            if(q.first == 'M') {
                unite(par2[q.second], q.second);
            } else {
                ans += find(q.second);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
