#include <iostream>
#include <string>
using namespace std;


const int MAX_N = 100000;
const long long int INF = 1000000000+7;
string s1, s2;
int d1, d2;

long long int dp[MAX_N+10][MAX_N+10];

long long int frac(long long int x) {
    return x%INF;
}

int main() {
    cin >> s1 >> d1 >> s2 >> d2;
    int s = s1.size();

    if(s1[0] == s2[0]) {
        dp[0][0] = 1; dp[1][1] = 1;
    } else {
        dp[0][1] = 1; dp[1][0] = 1;
    }
    // dp[0][0] = 1;
    for(int k = 1; k < s; k++) {
        cout << "=========================" << endl;
        for(int i = 0; i <= min(k+1, d1); i++) {
            for(int j = 0; j <= min(k+1, d2); j++) {
                if(s1[k] == s2[k]) {
                    if(i == 0 && j == 0) {
                        dp[i][j] = dp[i][j];
                    } else if(i == 0 && j != 0) {
                        dp[i][j] = dp[i][j];
                    } else if(i != 0 && j == 0) {
                        dp[i][j] = dp[i][j];
                    } else {
                        dp[i][j] = frac(dp[i-1][j-1] + dp[i][j]);
                    }
                } else {
                    if(i == 0 && j == 0) {
                        dp[i][j] = 0;
                    } else if(i == 0 && j != 0) {
                        dp[i][j] = dp[i][j-1];
                    } else if(i == 0 && j == 0) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j]= frac(dp[i-1][j] + dp[i][j-1]);
                    }
                }
                cout << "k: " << k+1 << ", i: " << i << ", j: " << j << ": " << dp[i][j] << " " << endl;;
            }
        }
    }
    cout << dp[d1][d2] << endl;
}
