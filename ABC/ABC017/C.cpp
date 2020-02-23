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

const int MAX_N = 100000, MAX_M = 100000, INF = (int)(1e9);

int N, M, l, r, s, ans;
int a[MAX_M + 5];

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> l >> r >> s;
        l--; r--;
        a[l] += s; a[r + 1] -= s;
        ans += s;
    }

    for(int i = 1; i <= M; i++) {
        a[i] += a[i - 1];
    }

    int m = INF;
    for(int i = 0; i < M; i++) {
        m = min(m, a[i]);
    }

    cout << ans - m << endl;

    return 0;
}
