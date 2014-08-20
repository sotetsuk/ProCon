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
    int a, b;
    cin >> a >> b;

    int ans;
    ans = min(abs(b - a), abs(b - (a + 10)));
    ans = min(ans, abs(b - (a - 10)));

    cout << ans << endl;
    return 0;
}
