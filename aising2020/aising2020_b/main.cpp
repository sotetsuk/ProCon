#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> a(N); for (int i = 0; i < N; ++i) cin >>a[i];
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if ((i + 1) % 2 == 1 && a[i] % 2 == 1) ++ans;
    }
    cout << ans << endl;
    return 0;
}
