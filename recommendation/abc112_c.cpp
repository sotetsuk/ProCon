#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P { int x, y, h; };

int main() {
    int N; cin >> N;
    vector<P> v;
    P p0{-1,-1,-1};
    for (int i = 0; i < N; ++i) {
        P p; cin >> p.x >> p.y >> p.h;
        if (p0.h < 0 && p.h > 0) p0 = p;
        v.emplace_back(p);
    }
    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            bool ok = true;
            int h = p0.h + abs(p0.x - cx) + abs(p0.y - cy);
            for (const auto &p: v) {
                int h_now = max(h - abs(p.x - cx) - abs(p.y - cy), 0);
                if (p.h != h_now) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << cx << " " << cy << " " << h << endl;
                return 0;
            }
        }
    }
    return 0;
}
