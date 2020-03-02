#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

int N, K;

int c[10];

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) c[i] = -1;
    int s, t;
    for (int i = 0; i < K; ++i) {
        cin >> s >> t;
        if (c[s] != -1 && t != c[s]) {
            cout << -1 << endl;
            return 0;
        }
        c[s] = t;
    }


    for (int i = 1; i <= N; ++i) {
        if (i == 1 && c[i] == -1 && N != 1) c[i] = 1;
        if (c[i] == -1) c[i] = 0;
    }

    if (c[1] == 0) {
        if (N == 1) {
            cout << 0 << endl;
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    int ans = 0;
    int l = 1;
    for (int i = N; i >= 1; --i) {
        ans += l * c[i];
        l *= 10;
    }
    cout << ans << endl;

    return 0;
}
