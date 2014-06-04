#include <iostream>
#include <queue>

using namespace std;

const int INF = 100000000;
const int MAX_X = 1000, MAX_Y = 1000, MAX_N = 9;
typedef pair<int, int> P;

int X, Y, N;
char grid[MAX_X+5][MAX_Y+5];
int dp[MAX_X+5][MAX_Y+5];
P chease_pos[MAX_X+5];
int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};

int bfs(P start_pos, P end_pos) {
    // search the min path from start_pos to end_pos
    queue<P> que;

    // initialize
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            dp[i][j] = INF;
        }
    }

    // first push
    que.push(start_pos);
    dp[start_pos.first][start_pos.second] = 0;

    while(que.size()) {
        // pop
        P p = que.front(); que.pop();

        // stop condition
        if(p == end_pos) break;

        // search
        for(int i = 0; i < 4; i++) {
            int nx = p.first+dx[i];
            int ny = p.second+dy[i];

            // grid check
            if(nx >= 0 && nx < X && ny >= 0 && ny < Y) {
                // check  X or not
                if(grid[nx][ny] != 'X') {
                    // whether first visit or not
                    if(dp[nx][ny] == INF) {
                        dp[nx][ny] = dp[p.first][p.second] + 1;
                        que.push(P(nx, ny));
                    }
                }
            }
        }

    }

    return dp[end_pos.first][end_pos.second];
}

int solve() {
    // input
    cin >> X >> Y >> N;
    for(int i = 0; i < X; i++) {
        cin >> grid[i];
    }

    P start_pos, end_pos;
    // search where chease exists and start_pos
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            if(grid[i][j] == 'S') {
                start_pos = P(i, j);
            } else if(grid[i][j] != 'X' && grid[i][j] != '.') {
                int num = (int)grid[i][j] - (int)'0';
                chease_pos[num] = P(i, j);
            }
        }
    }

    int count = 0;
    for(int i = 0; i < N; i++) {
        // set pos
        if(i != 0) {
            start_pos = end_pos;
        }
        end_pos = chease_pos[i+1];

        // bfs
        count += bfs(start_pos, end_pos);
    }

    cout << count << endl;
    return 0;
}


int main() {
    solve();
    return 0;
}
