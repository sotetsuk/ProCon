#include <iostream>
#include <math.h>
using namespace std;

const int MAX_N = 100000;
const int INF = 50000000;

int dp[MAX_N+5][MAX_N+5];
int N;
int A, B;


int debug() {
    cout << "====================" << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << dp[i][j];
        }
        cout << endl;
    }
    return 0;
}

int dfs(int i, int j) {
    if(dp[i][j]) {
        return dp[i][j];
    }
    if(i == j) {
        return 0;
    }

    int m = INF;
    for(int k = 0; k < N; k++) {
        if(!dp[i][k] && !dp[k][j]) {
            cout << "k: " << k << endl;
            m = min(m, dfs(i, k) + dfs(k, j));
        }
    }
    dp[i][j] = m;
    dp[j][i] = m;

    return 0;
}

int solve() {
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        cin >> A >> B;
        dp[A-1][B-1] = 1;
        dp[B-1][A-1] = 1;
    }

    int c = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            cout << i << " " << j << endl;
            debug();
            int c = max(c, dfs(i, j));
        }
    }
    cout << c << endl;
    return 0;
}


int main() {
    solve();
    return 0;
}
