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

const int MAX_V = 1000000;

int n, a, b;
int v[MAX_V + 10];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v[a] += 1; v[b + 1] -= 1;
    }
    for(int i = 1; i <= MAX_V; i++) {
        v[i] += v[i - 1];
    }
    int m = 0;
    for(int i = 0; i <= MAX_V; i++) {
        m = max(m, v[i]);
    }
    cout << m << endl;

    return 0;
}
