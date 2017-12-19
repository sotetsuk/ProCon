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

const int MAX_N = 100000;

string s;
int x, y;

int dpx[MAX_N];
int dpy[MAX_N];
int offset = MAX_N / 2;
bool init = true;

int update(int f, int *dp) {
    queue<int> q;
    for (int i = 0; i < MAX_N; ++i) {
        if (dp[i] == 1) {
            q.push(i + f);
            if (!init) q.push(i - f);
            dp[i] = 0;
        }
    }
    while (! q.empty()) {
        dp[q.front()] = 1;
        q.pop();
    }
    return 0;
}

int main() {
    cin >> s;
    cin >> x >> y;

    int c = 0;
    int oddeven = 0;
    dpx[offset] = 1;
    dpy[offset] = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'F') {
            c++;
            if (i != s.size() - 1) {
                continue;
            }
        }
        if (oddeven % 2 == 0) {
            update(c, dpx);
        } else {
            update(c, dpy);
        }
        c = 0;
        oddeven++;
        init = false;
    }

    if (dpx[offset + x] == 1 && dpy[offset + y] == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
