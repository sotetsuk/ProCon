#include <iostream>
using namespace std;

const int MAX_N = 350;

int N;
int A[MAX_N+5][MAX_N+5];

int dp[MAX_N+5][MAX_N+5];

int dfs(int n, int m) {
    if(dp[n][m]) return dp[n][m];
    if(n == N-1) return A[n][m];
    dp[n][m] = A[n][m] + max(dfs(n+1, m), dfs(n+1, m+1));
    return dp[n][m];
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> A[i][j];
        }
    }

    cout << dfs(0, 0) << endl;
    return 0;
}
