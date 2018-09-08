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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int n, x, a;
    cin >> n >> x;

    int ans = -1;

    for (int i = 0; i < n; i++) {
        cin >> a;
        a = abs(a - x);
        if (ans >= 0) {
            ans = gcd(ans, a);
        } else {
            ans = a;
        }
    }

    cout << ans << endl;

    return 0;
}