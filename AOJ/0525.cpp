#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
int mat[15][10005];
int mat2[15][10005];
int vec[10005];

int dfs(int num, int count) {
    if(count == 1) {
        return num;
    } else {
        count--;
        return num*dfs(num, count);
    }
}

int solve() {
    // input
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> mat[i][j];
        }
    }


    for(int i = 0; i < count(2, R); i++) {
        int v[R];
        for(int j = 0; j < R; j++) {
            v[j] = i%j;
        }

        for(int k = 0; k < R; k++) {
            if(v[k]) {
                for(int l = 0; l < C; l++) {
                    if(mat[k][l] == 1) {
                        mat2[k][l] = 0;
                    } else {
                        mat2[k][l] = 1;
                    }
                }
            }
        }

        for(int k = 0; k < R; k++) {
            for(int l = 0; l < C; l++) {
                if(k == 0) {
                    vec[l] = 0;
                }
                if(mat[0][l] != mat2[k][l]) {
                    vec[l]++;
                }
            }
        }

        for(int k = 0; k < R; k++) {
            if(vec)
        }

    }

    return 0;
}


int main(){
    solve();
    return 0;
}
