#include <iostream>
#include <queue>
using namespace std;

int const MAX_R = 50, MAX_C = 50;
int const INF = 300000000;
typedef pair<int, int> cord;

int R, C, sx, sy, gx, gy;
char grid[MAX_R+5][MAX_C+5];
int dp[MAX_R+5][MAX_C+5];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};

int solve() {
    // input
    cin >> R >> C;
    cin >> sx >> sy;
    cin >> gx >> gy;
    for(int i = 0; i < R; i++) {
        cin >> grid[i];
    }

    // initialize
    for(int i = 0; i < MAX_R; i ++) {
        for(int j = 0; j < MAX_C; j++) {
            dp[i][j] = INF;
        }
    }
    sx--;sy--;gx--;gy--;

    // bfs
    queue<cord> que;
    que.push(cord(sx, sy));
    dp[sx][sy] = 0;

    while(que.size()) {
        // pop
        cord now_cord = que.front();
        que.pop();

        // stop condition
        if(now_cord == cord(gx, gy)) {
            break;
        }


        // search
        for(int i = 0; i < 4; i++) {
            int nx = now_cord.first + dx[i];
            int ny = now_cord.second + dy[i];
            if(0 <= nx && nx < R && 0 <= ny && ny < C && grid[nx][ny] != '#') {
                // check whether first visit or not
                if(dp[nx][ny] == INF) {
                    que.push(cord(nx, ny));
                    dp[nx][ny] = dp[now_cord.first][now_cord.second] + 1;
                }
            }
        }
    }

    cout << dp[gx][gy] << endl;
    return 0;
}

int main() {
    solve();
    return 0;
}
