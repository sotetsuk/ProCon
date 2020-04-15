#include <iostream>

// namespace
using namespace std;

const int N = 8;
int dx[8] = {0, 1, 1,  1, -1, -1,  0, -1};
int dy[8] = {1, 1, 0, -1,  0, -1, -1,  1};

void set_val(int x, int y, int a[8][8], int pos[8], int val) {
    if (val > 0) pos[x] = y;
    else pos[x] = -1;
    a[x][y] += val;
    for (int k = 0; k < 8; ++k) {
        for (int l = 1; l < 8; ++l) {
            int next_x = x + l * dx[k];
            int next_y = y + l * dy[k];
            if (0 <= next_x && next_x < 8 && 0 <= next_y && next_y < 8)
                a[next_x][next_y] += val;
        }
    }
}

void show_board(const int pos[8]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << (pos[i] == j ? 'Q' : '.');
        }
        cout << endl;
    }
}

bool solve_queen(int col, int a[8][8], int pos[8]) {
    if (col == 8) return true;
    if (pos[col] != -1) return solve_queen(col + 1, a, pos);
    for (int row = 0; row < 8; ++row) {
        if (a[col][row] == 0) {
            set_val(col, row, a, pos, +1);
            bool success = solve_queen(col + 1, a, pos);
            if (success) return true;
            set_val(col, row, a, pos, -1);
        }
    }
    return false;
}

int main() {
    int a[N][N];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            a[i][j] = 0;
    int pos[8];
    for (int i = 0; i < 8; ++i) pos[i] = -1;

    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        set_val(x, y, a, pos, true);
    }

    solve_queen(0, a, pos);
    show_board(pos);

   return 0;
}
