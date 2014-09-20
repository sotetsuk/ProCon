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

const int MAX_N = 1000000;

int N;
bool c[MAX_N][MAX_N];
bool visited[MAX_N];

int dfs(int n, int t) {
    if(n == t || visited[n]) {
        return 0;
    }
    else visited[n] = true;

    int s = 1;
    for(int i = 0; i < N; i++) {
        if(c[n][i]) {
            s += dfs(i, t);
        }
    }
    return s;
}


int main() {
    cin >> N;
    int p;
    for(int i = 1; i < N; i++) {
        cin >> p;
        c[i][p] = true;
        c[p][i] = true;
    }

    for(int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        int m = 0;
        for(int j = 0; j < N; j++) {
            if(c[i][j]) {
                m = max(dfs(j, i), m);
            }
        }
        cout << m << endl;
    }

    return 0;
}
