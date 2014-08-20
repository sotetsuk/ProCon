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
#include <sstream>

using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

int main() {
    int n, h;
    int a, b, c, d, e;
    cin >> n >> h;
    cin >> a >> b >> c >> d >> e;

    ll ans = 0;
    if(1.0*b/a > 1.0*d/c) {
        ll l_ans;
        int l_h, l_n;
        for(; n > 0; n--) {
            if(h - e < 0) {
                l_n = n;
                l_ans = ans;
                l_h = h;
                ans += a;
                h += b;
            } else {
                h -= e;
            }
        }
        for(; l_n > 0; l_n--) {
            if(l_h - e < 0) {
                l_ans += c;
                l_h += d;
            } else {
                l_h -= e;
            }
        }
        ans = min(ans, l_ans);
    } else {
        for(; n > 0; n--) {
            if(h - e < 0) {
                ans += c;
                h += d;
            } else {
                h -= e;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
