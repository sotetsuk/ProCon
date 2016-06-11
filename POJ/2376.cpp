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

const int MAX_N = 25000 + 5;
const int MAX_T = 1000000 + 5;

int N, T, l, r;
vector<pii> p;

int main() {
    // input
    scanf("%d %d", &N, &T);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &l, &r);
        p.push_back(pii(l, r));
    }
    p.push_back(pii(T+1, T+1)); // dummy extra input

    sort(p.begin(), p.end());

    int now = 0;
    int m = -1;
    int ans = 0;
    for(int i = 0; i < N + 1; i++) {
        if(p[i].first - now <= 1) {
            m = max(m, p[i].second);
        } else if(m > now) {
            now = m;
            m = -1;
            ans++; i--;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    if(now < T) ans = -1;
    cout << ans << endl;

    return 0;
}
