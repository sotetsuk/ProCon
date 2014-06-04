#include <iostream>

using namespace std;

const int MAX_X = 20;
const int MAX_Y = 20;

int size_x, size_y;

// set field
char field[MAX_X+3][MAX_Y+3];

int dfs(int x, int y) {
    // check size
    if(x < 0 || x >= size_x || y < 0 || y >= size_y) {
        return 0;
    }

    // dfs
    if(field[x][y] == '@') {
        return 0;
    } else if(field[x][y] == '#') {
        return 0;
    } else {
        field[x][y] = '@';
        return dfs(x+1, y) + dfs(x, y+1) + dfs(x-1, y) + dfs(x, y-1) + 1;
    }
}

int solve(int size_x, int size_y) {
    // input
    for(int i = 0; i < size_x; i++) {
        cin >> field[i];
    }

    // search @ and initialize x, y
    int x, y;
    for(int i = 0; i < size_x; i++) {
        for(int j = 0; j < size_y; j++) {
            if(field[i][j] == '@') {
                x = i;
                y = j;
            }
        }
    }

    // Depth-First Search
    field[x][y] = '.';
    // debug
    // cout << x << "," << y << endl;
    cout << dfs(x, y) << endl;

    return 0;
}

int main() {
    while(true){
        cin >> size_y >> size_x;
        if(size_x == 0 && size_y == 0) break;

        solve(size_x, size_y);

        // debug
        // for(int i = 0; i < size_x; i++) {
        //     cout << field[i] << endl;
        // }
    }
    return 0;
}
