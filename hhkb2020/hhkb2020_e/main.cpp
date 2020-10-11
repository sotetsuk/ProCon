#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    using mint = atcoder::modint1000000007;
    int H, W; cin >> H >> W;
    vector<string> S(H); for (int i = 0; i < H; ++i) cin >> S[i];
    vector<vector<int>> cnt(H, vector<int>(W, 1));

    // 4方向から照らしてくるライトの個数を数える
    for (int i = 0; i < H; ++i)  {
        int curr = 0;
        for (int j = 0; j < W; ++j) {
            if (S[i][j] != '.') {
                curr = 0;
                continue;
            }
            cnt[i][j] += curr;
            curr++;
        }
    }
    for (int i = 0; i < H; ++i) {
        int curr = 0;
        for (int j = W - 1; j >= 0; --j) {
            if (S[i][j] != '.') {
                curr = 0;
                continue;
            }
            cnt[i][j] += curr;
            curr++;
        }
    }
    for (int j = 0; j < W; ++j) {
        int curr = 0;
        for (int i = 0; i < H; ++i)  {
            if (S[i][j] != '.') {
                curr = 0;
                continue;
            }
            cnt[i][j] += curr;
            curr++;
        }
    }
    for (int j = 0; j < W; ++j) {
        int curr = 0;
        for (int i = H - 1; i >= 0; --i)  {
            if (S[i][j] != '.') {
                curr = 0;
                continue;
            }
            cnt[i][j] += curr;
            curr++;
        }
    }

    // 障害物がない箇所の個数
    int K = 0; for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) if (S[i][j] == '.') ++K;

    // 数え上げる
    mint ans = mint(K) * mint(2).pow(K);  // 全パターン
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] != '.') continue;
            ans -= mint(2).pow(K - cnt[i][j]);
        }
    }

    // for (int i = 0; i < H; ++i) {
    //     for (int j = 0; j < W; ++j) {
    //         cout << cnt[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    cout << ans.val() << endl;

    return 0;
}
