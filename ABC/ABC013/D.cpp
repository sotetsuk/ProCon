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

const int MAX_N = 100000, MAX_M = 2 * 100000, MAX_LOG_D = 30;

int N, M, D;
int A[MAX_M + 10];
int to[MAX_N];
int to_k[MAX_LOG_D][MAX_N];

int main() {
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++) to[i] = i;
    int a;
    for(int i = 0; i < M; i++) {
        cin >> a; a--;
        swap(to[a], to[a + 1]);
    }

    // 2^k回作用させた時の結果をメモ
    for(int i = 0; i < N; i++) to_k[0][i] = to[i];

    for(int k = 1; k < MAX_LOG_D; k++) {
        for(int i = 0; i < N; i++) {
            to_k[k][i] = to_k[k - 1][to_k[k - 1][i]];
        }
    }

    // 作用させる
    for(int i = 0; i < N; i++) {
        int j = i;
        int d = D;
        for(int k = 0; k < MAX_LOG_D; k++) {
            if(d >> k & 1) {
                j = to_k[k][j];
            }
        }

        to[j] = i;
    }

    // 結果を表示
    for(int i = 0; i < N; i++) {
        cout << ++to[i] << endl;
    }

    return 0;
}
