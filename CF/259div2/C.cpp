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
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

const int MAX_M = 100000, MAX_N = 100000;

int m, n;

int main() {
    cin >> m >> n;

    double t = 1;
    double ans = 0;
    for(int i = m; i > 0; i--) {
        double tmp = pow(1.0*(i-1)/m, n);
        t -= tmp;
        ans += i * t;
        t = tmp;
    }

    printf("%.7f\n", ans);

    return 0;
}
