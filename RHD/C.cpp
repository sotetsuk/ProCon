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

const int MAX_N = 10000, MAX_Q = 100, MAX_NUM = 10000;

int N, Q;

int A[MAX_N + 10];
int X[MAX_Q + 10];
int mat[MAX_NUM + 10][MAX_Q + 10];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> X[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < Q; j++) {
            mat[A[i] % X[j]][j]++;
        }
    }

    for(int j = 0; j < Q; j++) {
        // cout << X[j] << " "; // debug
        int ans = 0;
        for(int i = 0; i <= X[j] / 2; i++) {
            if(i == 0 ) {
                ans += mat[i][j] * (mat[i][j] - 1) / 2;
            } else {
                if(i == X[j] - i) {
                    ans += mat[i][j] * (mat[i][j] - 1) / 2;
                } else {
                    ans += mat[i][j] * mat[X[j] - i][j];
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
