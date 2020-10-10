#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H); for (int i = 0; i < H; ++i) cin >> S[i];
    int cnt = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] != '.') continue;
            if (i + 1 < H && S[i + 1][j] == '.') ++cnt;
            if (j + 1 < W && S[i][j + 1] == '.') ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
