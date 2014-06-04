#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> coin;

const int INF = 2000000000;
const int max_N = 20, max_C = 100000000;
const int max_V = 100000000, max_B = 1000000;
int N, C;
vector<coin> coins;

int solve() {
    vector<int> v;
    int use[coins.size()];
    int remain = C;

    int i = N-1;
    int j = INF;

    while(remain > 0) {
        if(i == -1) {
            if(j == INF) {
                return -1;
            }
            v.push_back(j);
            use[j]++;
            break;
        }

        if(coins[i].second - use[i] > 0) {
            int next_remain = remain - coins[i].first;
            if(next_remain == 0) {
                bool flag = true;
                for(int j = 0; j < v.size(); j++) {
                    if (i == v[j]) {
                        flag = false;
                    }
                }
                if(flag) {
                    v.push_back(i);
                }
                use[i]++;
                remain = next_remain;
            } else if(next_remain > 0) {
                bool flag = true;
                for(int j = 0; j < v.size(); j++) {
                    if (i == v[j]) {
                        flag = false;
                    }
                }
                if(flag) {
                    v.push_back(i);
                }
                use[i]++;
                remain = next_remain;
            } else {
                j = i;
                i--;
            }
        } else {
            i--;
        }
    }

    int m = INF;
    cout << v.size() << endl;

    for(int i = 0; i < v.size(); i++) {
         cout << "v[i]: " << v[i] << endl;
         m = min(m, coins[v[i]].second / use[v[i]]);
    }

    for(int i = 0; i < v.size(); i++) {
        coins[v[i]].second -= m * use[v[i]];
    }

    return m;
}

int main() {
    int V, B;
    cin >> N >> C;
    for(int i = 0; i < N; i++) {
        cin >> V >> B;
        coins.push_back(coin(V, B));
    }

    sort(coins.begin(), coins.end());

    int ans = 0;
    while(true) {
        // debug ////////
        cout << "===========================" << endl;
        for(int i = 0; i < coins.size(); i++) {
            cout << coins[i].first << " " << coins[i].second << endl;
        }
        ///////////////


        int tmp = solve();

        /// debug
        cout << "tmp: " << tmp << endl;
        ////

        if(tmp == -1) {
            break;
        } else {
            ans += tmp;
        }
    }

    cout << ans << endl;

    return 0;
}
