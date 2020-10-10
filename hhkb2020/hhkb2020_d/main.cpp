#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;

ll solve(int N, int A, int B) {
    mint ans = mint(N - A + 1).pow(2) * mint(N - B + 1).pow(2);
    mint Y = mint(N - A + 1) * (N - B + 1);
    mint X = (N - A - B) >= 0 ? mint(N - A - B + 2) * mint(N - A - B + 1): 0;
    ans -= (Y - X).pow(2);
    return ans.val();
}

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, A, B; cin >> N >> A >> B;
        cout << solve(N, A, B) << endl;
    }
    return 0;
}
