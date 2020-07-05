#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, K; cin >> H >> W >> K;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) cin >> grid[i];
    int ans = 0;
    for (int k = 0; k < 1<<(H + W); ++k) {
        int cnt = 0;
        for (int i = 0; i < H; ++i) {
            if ((1<<i)&k) continue;
            for (int j = 0; j < W; ++j) {
                if (1<<(H+j)&k) continue;
                if (grid[i][j] == '#') ++cnt;
            }
        }
        if (cnt == K) ++ans;
    }
    cout << ans << endl;
    return 0;
}
