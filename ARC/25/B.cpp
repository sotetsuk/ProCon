#include <iostream>
using namespace std;

int H, W;
int C[105][105];

int dp[105][105];


int main() {
    // input
    cin >> H >> W;
    int c;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> c;
            if((i+j)%2 == 0) {
                C[i][j] = c;
            } else {
                C[i][j] = -c;
            }
        }
    }

    // solve
    int m = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            for(int l = i; l < H; l++) {
                for(int k = j; k < W; k++) {
                    if(l == i && j == k) {
                        dp[i][j] = C[i][j];
                    } else if(l == i) {
                        dp[l][k] = dp[l][k-1] + C[l][k];
                    } else if(k == j) {
                        dp[l][k] = dp[l-1][k] + C[l][k];
                    } else {
                        dp[l][k] = dp[l-1][k] + dp[l][k-1] - dp[l-1][k-1] + C[l][k];
                    }
                    if(dp[l][k] == 0) {
                        m = max((l-i+1)*(k-j+1), m);
                    }
                }
            }
        }
    }

    cout << m << endl;

    return 0;
}
