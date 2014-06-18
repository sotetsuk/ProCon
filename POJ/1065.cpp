#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

const int MAX_N = 5000;
int T, N;
int l[MAX_N+5];
int w[MAX_N+5];
int dp[MAX_N+5];

int dfs(vector<P> &v) {
    int ret = 0;
    for(int i = 0; i < v.size(); i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(v[i].second < v[j].second) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ret = max(ret, dp[i]);
    }

    return ret;
}

int solve() {
    vector<P> v;
    for(int i = 0; i < N; i++) {
        P p = P(l[i], w[i]);
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    int ans = dfs(v);
    cout << ans << endl;
    return 0;
}

int main() {
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N;
        for(int j = 0; j < N; j ++) {
            cin >> l[j] >> w[j];
        }
        solve();
    }
    return 0;
}
