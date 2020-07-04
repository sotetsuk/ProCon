#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<int> b(10);
    for (int i = 0; i < 10; ++i) {
        int j; cin >> j;
        b[j] = i;
    }
    int N; cin >> N;
    vector<int> a(N);
    for (int & e: a) cin >> e;

    auto comp = [&](int x, int y) {
        string x_str = to_string(x);
        string y_str = to_string(y);
        if (x_str.size() != y_str.size()) return x_str.size() < y_str.size();
        for (int i = 0; i < x_str.size(); ++i) {
            int cx = x_str[i] - '0';
            int cy = y_str[i] - '0';
            if (cx != cy) return b[cx] < b[cy];
        }
        return true;
    };

    sort(a.begin(), a.end(), comp);
    for (const auto &e: a) cout << e << endl;
    return 0;
}
