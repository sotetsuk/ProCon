#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> f(N + 1);
    for (int x = 1; x * x <= N; ++x) {
        for (int y = 1; y * y <= N; ++y) {
            for (int z = 1; z * z <= N; ++z) {
                int lhs = x*x + y*y + z*z + x*y + y*z + z*x;
                if (lhs > N) continue;
                f[lhs]++;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << f[i] << endl;
    }
}

