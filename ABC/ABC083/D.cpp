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

string s;

int main() {
    cin >> s;

    int n = s.size();
    int ans = n;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i + 1]) {
            int x = max(i + 1, n - i - 1);
            ans = min(ans, x);
        }
    }
    cout << ans << endl;
}
