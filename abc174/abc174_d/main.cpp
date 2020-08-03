#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    string s; cin >> s;
    int cnt = 0;
    int l = 0, r = N - 1;
    while (l < r) {
        if (s[l] == 'R') {
            ++l; continue;
        }
        if (s[r] == 'W') {
            --r; continue;
        }
        swap(s[l], s[r]) ;
        ++cnt;
        ++l; --r;
    }
    cout << cnt << endl;
    return 0;
}
