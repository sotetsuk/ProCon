#include <iostream>
using namespace std;

const int MAX_N = 350;

int N;
int A[MAX_N+5][MAX_N+5];

int dp[MAX_N+5][MAX_N+5];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = N-1; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            if (i == N-1) {
                dp[i][j] = A[i][j];
            } else {
                dp[i][j] = A[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
            }
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}
