#include <iostream>
#include <cstdio>
using namespace std;

int N, D;
int X, Y;
const int MAX_N = 100;

long long int dp[MAX_N*2+5][MAX_N*2+5][MAX_N+5];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int get_cord(int x) {
    return x+MAX_N;
}

long long int dfs(int x, int y, int n) {
    if(dp[get_cord(x)][get_cord(y)][n] != -1) return dp[get_cord(x)][get_cord(y)][n];
    if(n == 0) return dp[get_cord(x)][get_cord(y)][n];

    long long int count = 0;
    for(int i = 0; i < 4; i++) {
        count += dfs(x - dx[i], y - dy[i], n - 1);
    }

    return dp[get_cord(x)][get_cord(y)][n] = count;
}

int main() {
    cin >> N >> D;
    cin >> X >> Y;

    if(X%D || Y%D) {
        cout << 0 << endl;
        return 0;
    } else {
        X = X/D;
        Y = Y/D;
    }

    if(X > N || Y > N || X < -N || Y < -N) {
        cout << 0 << endl;
        return 0;
    }


    // dfs
    for(int i = 0; i < 2*MAX_N+5; i++) {
        for(int j = 0; j < 2*MAX_N+5; j++) {
            for(int n = 0; n < MAX_N+5; n++) {
                if(n == 0) {
                    dp[i][j][n] = 0;
                } else {
                    dp[i][j][n] = -1;
                }
            }
        }
    }
    dp[get_cord(0)][get_cord(0)][0] = 1;
    long double ans = dfs(X, Y, N);

    for(int i = 0; i < N; i++) {
        ans /= 4.0;
    }

    printf("%.15LF\n", ans);

    return 0;
}
