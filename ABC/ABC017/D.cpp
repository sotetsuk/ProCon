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

const int MAX_N = 100000, MAX_M = 100000, DIV = 1000000007;
int N, M;
int f[MAX_N + 5];
bool used_N[MAX_N], used_M[MAX_M];

int dfs(int n, int m) {
    int ret = 0;
    bool flag = false;
    for(int i = 0; i < N; i++) {
        if(!used_N[i] && !used_M[f[i]]) {
            used_N[i] = true; used_M[f[i]] = true;
            ret += dfs(i, m); ret %= DIV;
        }
        used_N[i] = true;
        memset(used_M, 0, sizeof(used_M));
        ret += dfs(i, m + 1); ret %= DIV;
    }

    used_N[n] = false; used_M[f[n]] = false;
    return ret % DIV;
}


int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> f[i];
        f[i]--;
    }

    used_N[0] = true; used_M[f[0]] = true;
    cout << dfs(0, 0) << endl;

    return 0;
}
