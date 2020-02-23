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

const int MAX_N = 50, MAX_W = 10000;
int W, N, K, A, B;

int dp[MAX_N + 10][MAX_W + 10][MAX_N + 10];
int weights[MAX_N];
int values[MAX_N];

int dfs(int i, int w, int k) {
    if(dp[i][w][k] >= 0) return dp[i][w][k];
    if(i == N) return 0;

    if(w + weights[i] > W || k >= K) {
        dp[i][w][k] = dfs(i + 1, w, k);
    } else {
        dp[i][w][k] = max(dfs(i + 1, w, k), dfs(i + 1, w + weights[i], k + 1) + values[i]);
    }

    return dp[i][w][k];
}

int main() {
    cin >> W;
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> A >> B;
        weights[i] = A; values[i] = B;
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0, 0) << endl;
    return 0;
}
