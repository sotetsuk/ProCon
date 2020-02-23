#include <iostream>

using namespace std;

const int MAX_X = 4, MAX_Y = 4;

int grid[MAX_X][MAX_Y];

int solve() {
    for(int i = 0; i < MAX_X; i++) {
        for(int j = 0; j < MAX_Y; j++) {
            cin >> grid[i][j];
        }
    }

    string ans = "GAMEOVER";
    for(int i = 0; i < MAX_X; i++) {
        for(int j = 0; j < MAX_Y; j++) {
            // check top
            if(i != 0) {
                if(grid[i][j] == grid[i-1][j]) {
                    ans = "CONTINUE";
                    break;
                }
            }
            // check down
            if(i != MAX_X-1) {
                if(grid[i][j] == grid[i+1][j]) {
                    ans = "CONTINUE";
                    break;
                }
            }
            // check left
            if(j != 0) {
                if(grid[i][j] == grid[i][j-1]) {
                    ans = "CONTINUE";
                    break;
                }
            }
            // check right
            if(j != MAX_Y-1) {
                if(grid[i][j] == grid[i][j+1]) {
                    ans = "CONTINUE";
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

int main() {
    solve();
    return 0;
}
