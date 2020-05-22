#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> c(N);
    for (int i = 0; i < N; ++i) cin >> c[i];
    vector<int> dp(N + 1, INT_MAX);
    for (auto &e: c) *lower_bound(dp.begin(), dp.end(), e) = e;
    int lis = lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
    cout << N - lis << endl;
    return 0;
}
