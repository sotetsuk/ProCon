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

int N, M, A, B;
int mat[10][10];
int v[10];

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> A >> B;
        A--; B--;
        mat[A][B] = 1; mat[B][A] = 1;
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            v[j] = 0;
        }
        for(int j = 0; j < N; j++) {
            if(mat[i][j]) {
                for(int k = 0; k < N; k++) {
                    if(mat[k][j]) v[k] = 1;
                }
            }
        }
                for(int j = 0; j < N; j++) {
            if(i == j || mat[i][j]) v[j] = 0;
        }
        int s = 0;
        for(int j = 0; j < N; j++) {
            s += v[j];
        }
        cout << s << endl;
    }

    return 0;
}
