#include <iostream>
using namespace std;

int N;
int NG[3];
int dp[305][105];

int dfs(int N, int c) {
    if(dp[N][c]) return dp[N][c];

    int ret = -1;
    for(int i = 1; i <= 3; i++) {
        if(N-i >= 0) {
            dp[N-i][c+1] = dfs(N-i, c+1);
            ret = max(ret, dp[N-i][c+1]);
        }
    }

    dp[N][c] = ret;
    return ret;
}

int main() {
    // input
    cin >> N;
    for(int i = 0; i < 3; i++) {
        cin >> NG[i];
    }

    // dfs
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 105; i++) {
            dp[NG[j]][i] = -1;
        }
    }
    for(int i = 0;i < 105; i++) {
        dp[0][i] = 1;
    }
    for(int i = 0; i < 305; i++) {
        dp[i][101] = -1;
    }


    int ret;
    ret = dfs(N, 0);

    if(ret == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
