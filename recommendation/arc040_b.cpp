#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, R; cin >> N >> R;
    string S; cin >> S;
    int ans = 0;
    int rightmost_uncovered = N - 1;
    while (S[rightmost_uncovered] == 'o') {
        rightmost_uncovered--;
        if (rightmost_uncovered < 0) break;
    }
    ans += max(0, rightmost_uncovered - R + 1);
    int i = N - 1;
    while(i >= 0) {
        if (S[i] == 'o') {
            --i;
        } else {
            i = i - R;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

