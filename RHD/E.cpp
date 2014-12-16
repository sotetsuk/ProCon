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
#include <map>
#include <sstream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

const int MAX_V = 100000, DIV = 1000000007;

vector<int> G[MAX_V];
int root = 0;
int parent[MAX_V];

int N, a, b;

int dp[2][MAX_V];

int dfs(int defenced, int node) {
    // cout << defenced << " " << node << " " << parent[node] << endl; // debug
    if(dp[defenced][node] != -1) return dp[defenced][node];
    if(G[node].size() == 1) return dp[defenced][node] = 1;
    int ret = 0;
    for(int i = 0; i < G[node].size(); i++) {
        // cout << " " << node << " " << G[node][i] << endl; // debug
        if(G[node][i] != parent[node]) {
            if(defenced) {
                ret += dfs(0, G[node][i]) % DIV;
                ret += dfs(1, G[node][i]) % DIV;
            } else {
                int tmp = 0;
                tmp += dfs(1, G[node][i]) % DIV;
                tmp %= DIV;
                for(int j = 0; j < G[node].size(); j++) {
                    if(G[node][j] != parent[node] && i != j) {
                        tmp *= dfs(0, G[node][j]) % DIV;
                        tmp %= DIV;
                    }
                }
                ret += tmp % DIV;
            }
        }
    }

    dp[defenced][node] = ret;
    return ret % DIV;
}

void dfs_init(int node, int p) {
    parent[node] = p;
    for(int i = 0; i < G[node].size(); i++) {
        if(G[node][i] != p) dfs_init(G[node][i], node);
    }
}

// 初期化
void init() {
    // parent と depth を初期化する
    dfs_init(root, -1);
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // parent[root] = -1;
    init();
    // cout << "debug2" << endl; // debug
    // cout << parent[0] << " " << parent[1] << " " << parent[2] << " " << endl; // debug

    memset(dp, -1, sizeof(dp));

    dfs(0, root);
    dfs(1, root);

    cout << (dp[0][root] + dp[1][root]) % DIV << endl;


    // debug
    // cout << dp[0][0] << " " << dp[0][1] << " " << dp[0][2] << " " << endl;
    // cout << dp[1][0] << " " << dp[1][1] << " " << dp[1][2] << " " << endl;
    return 0;
}
