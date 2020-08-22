#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, M; cin >> H >> W >> M;
    unordered_map<int, int> x_counter;
    unordered_map<int, int> y_counter;
    unordered_map<int, unordered_set<int>> bombs;
    auto has = [&](int x, int y){
        if (bombs.count(x) == 0) return false;
        return static_cast<bool>(bombs.at(x).count(y));
    };
    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y; --x; --y;
        bombs[x].insert(y);
        x_counter[x]++;
        y_counter[y]++;
    }
    vector<pair<int, int>> vx;
    vector<pair<int, int>> vy;
    for (auto [x, c]: x_counter) {
        vx.emplace_back(c, x);
    }
    for (auto [y, c]: y_counter) {
        vy.emplace_back(c, y);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    reverse(vx.begin(), vx.end());
    reverse(vy.begin(), vy.end());
    int ans = 0;
    for (int i = 0; i < min(vx.size(), (unsigned long)100); ++i) {
        for (int j = 0; j < vy.size(); ++j) {
            int x = vx[i].second;
            int x_count = vx[i].first;
            int y = vy[j].second;
            int y_count = vy[j].first;
            if (has(x, y)) {
                // cout << "*";
                // cout << x + 1 << " " << y + 1 << " " << x_count << " " << y_count << " " << x_count + y_count - 1 << endl;
                ans = max(ans, x_count + y_count - 1);
            } else {
                // cout << " ";
                // cout << x + 1 << " " << y + 1 << " " << x_count << " " << y_count << " " << x_count + y_count << endl;
                ans = max(ans, x_count + y_count);
            }
        }
    }
    for (int i = 0; i < vx.size(); ++i) {
        for (int j = 0; j < min(vy.size(), (unsigned long)100); ++j) {
            int x = vx[i].second;
            int x_count = vx[i].first;
            int y = vy[j].second;
            int y_count = vy[j].first;
            if (has(x, y)) {
                // cout << "*";
                // cout << x + 1 << " " << y + 1 << " " << x_count << " " << y_count << " " << x_count + y_count - 1 << endl;
                ans = max(ans, x_count + y_count - 1);
            } else {
                // cout << " ";
                // cout << x + 1 << " " << y + 1 << " " << x_count << " " << y_count << " " << x_count + y_count << endl;
                ans = max(ans, x_count + y_count);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
