#include <stack>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_X = 50, MAX_Y = 50;

int T, R, C, M;
char grid1[MAX_X+5][MAX_Y+5];
int grid2[MAX_X+5][MAX_Y+5];

int show_grid() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << grid1[i][j];
        }
        cout << endl;
    }

    // debug
    // cout << "-----" << endl;
    // for(int i = 0; i < R; i++) {
    //     for(int j = 0; j < C; j++) {
    //         cout << grid2[i][j];
    //     }
    //     cout << endl;
    // }

    return 0;
}

int initialize_grid() {
    for(int i = 0; i < MAX_X+5; i++) {
        for(int j = 0; j < MAX_Y+5; j++) {
            grid1[i][j] = '*';
            grid2[i][j] = 0;
        }
    }
    return 0;
}

int count_around_mine(int x, int y) {
    int count = 0;
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            //check size of x, y
            if(x+dx < 0|| x+dx >= R || y+dy < 0 || y+dy >= C) continue;

            // count
            if(grid1[x+dx][y+dy] == '*') {
                count++;
            }
        }
    }
    return count;
}

int can_be_move(int x, int y) {
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            //check size of x, y
            if(x+dx < 0|| x+dx >= R || y+dy < 0 || y+dy >= C) continue;

            // check
            if(grid2[x+dx][y+dy]) return 1;
        }
    }

    return 0;
}

int dfs(int i, int j, int remain) {
    if(remain == 0) {
        show_grid();
        return 1;
    }

    // // debug
    // cout << "============" << endl;
    // cout << i << " " << j << " " << remain << " " << remain_zero << endl;
    // show_grid();

    stack <int> xs;
    stack <int> ys;

    int count = count_around_mine(i, j);
    if(remain - count >= 0) {
        grid2[i][j] = 1;
        for(int dx = -1; dx <= 1; dx++) {
            for(int dy = -1; dy <= 1; dy++) {
                //check size of x, y
                if(i+dx < 0|| i+dx >= R || j+dy < 0 || j+dy >= C) continue;

                if(grid1[i+dx][j+dy] == '*') {
                    grid1[i+dx][j+dy] = '.';
                    xs.push(i+dx);
                    ys.push(j+dy);
                }
            }
        }

        for(int dx = -1; dx <= 1; dx++) {
            for(int dy = -1; dy <= 1; dy++) {
                //check size of x, y
                if(i+dx < 0|| i+dx >= R || j+dy < 0 || j+dy >= C) continue;

                if(can_be_move(i+dx, j+dy)) {
                    if(dfs(i+dx, j+dy, remain-count)) {
                        return 1;
                    }

                }
            }
        }
    }

    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            //check size of x, y
            if(i+dx < 0|| i+dx >= R || j+dy < 0 || j+dy >= C) continue;

            if(can_be_move(i+dx, j+dy)) {
                if(grid1[i+dx][j+dy] == '*') {
                    grid1[i+dx][j+dy] = '.';
                    if(dfs(i+dx, j+dy, remain-1)) {
                        return 1;
                    }
                    grid1[i+dx][j+dy] = '*';
                }
            }
        }
    }

    grid2[i][j] = 0;

    if(remain - count >= 0) {
        for(int i = 0; i < count; i++) {
            grid1[xs.top()][ys.top()] = '*';
            xs.pop();
            ys.pop();
        }
    }

    return 0;
}

int solve(int n) {
    printf("Case #%d:\n", n+1);
    bool flag = false;
    int remain = R*C-M-1;
    grid1[0][0] = 'c';
    if(dfs(0, 0, remain)) {
        flag = true;
    }
    if(!flag) {
        cout << "Impossible" << endl;
    }
    return 0;
}

int main() {
    cin >> T;
    for(int n = 0; n < T; n++) {
        cin >> R >> C >> M;
        initialize_grid();
        solve(n);
    }
    return 0;
}
