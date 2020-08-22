#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H, W, sx, sy, gx, gy;
int grid[1005][1005];

void dfs(int x, int y, int c) {
    if (x < 0 || y < 0 || x >= H || y >= W) return;
    if (grid[x][y] == -2 || (grid[x][y] >= 0 && grid[x][y] <= c)) return;
    grid[x][y] = c;
    dfs(x - 1, y, c);
    dfs(x + 1, y, c);
    dfs(x, y + 1, c);
    dfs(x, y - 1, c);
    for (int i = x - 2; i <= x + 2; ++i) {
        for (int j = y - 2; j <= y + 2; ++j) {
            dfs(i, j, c + 1);
        }
    }
}

void dump() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] < 0) {
                if (grid[i][j] == -2) cout << "#" << " ";
                else cout << "." << " ";
            } else {
                cout<< grid[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    cin >> H >> W >> sx >> sy >> gx >> gy;
    --sx; --sy; --gx; --gy;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c;
            cin >> c;
            if (c == '.') {
                grid[i][j] = -1;
            } else {
                grid[i][j] = -2;
            }
        }
    }
    // dump();
    // dfs(sx, sy, 0);
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, {sx, sy}});
    while(!q.empty()) {
        int c = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if (x == gx && y == gy) {
            cout << -c << endl;
            return 0;
        }
        if (grid[x][y] == -1) {
            grid[x][y] = -c;
            if (x + 1 < H) q.push({c, {x + 1, y}});
            if (x - 1 >= 0) q.push({c, {x - 1, y}});
            if (y + 1 < W) q.push({c, {x, y + 1}});
            if (y + 1 >= 0) q.push({c, {x, y - 1}});
            for (int i = x - 2; i <= x + 2; ++i) {
                for (int j = y - 2; j <= y + 2; ++j) {
                    if (i == x && j == y) continue;
                    if (i == x - 1 && j == y) continue;
                    if (i == x + 1 && j == y) continue;
                    if (i == x && j == y + 1) continue;
                    if (i == x && j == y - 1) continue;
                    if (i >= 0 && j >= 0 && i < H && j < W) {
                        q.push({c - 1, {i, j}});
                    }
                }
            }
        }
    }
    // dump();
    if (grid[gx][gy] < 0) {
        cout << "-1" << endl;
    } else {
        cout << grid[gx][gy] << endl;
    }

    return 0;
}
