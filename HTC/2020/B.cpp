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

int A, B, M, x, y, c;
int a[100005];
int b[100005];

int main() {
    int ans = INT_MAX;
    int m_a = INT_MAX;
    int m_b = INT_MAX;

    cin >> A >> B >> M;

    for (int i = 1; i <= A; ++i) {
        cin >> a[i];
        m_a = min(a[i], m_a);
    }

    for (int i = 1; i <= B; ++i) {
        cin >> b[i];
        m_b = min(b[i], m_b);
    }

    ans = min(ans, m_a + m_b);

    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> c;
        ans = min(ans, a[x] + b[y] - c);
    }

    cout << ans << endl;

    return 0;
}
