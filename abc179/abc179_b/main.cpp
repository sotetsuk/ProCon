#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    int cnt = 0;
    bool ok = false;
    for (int i = 0; i < N; ++i) {
        int d1, d2; cin >> d1 >> d2;
        if (d1 == d2) cnt++;
        else cnt = 0;
        if (cnt == 3) {
            ok = true;
            break;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
