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

const int MAX_N = 100000, MAX_M = 100000;

int N, M, D;
int a[MAX_N+1];
int ans[MAX_N+1];

int main() {
    cin >> N >> M >> D;

    int A;
    for(int m = 0; m < M; m++) {
        cin >> A;
        swap(a[A], a[A+1]);
    }

    for(int k = 1; k <= N; k++) {
        int i = k;
        for(int d = 0; d < D; d++) {
            i = a[i];
        }
        ans[k] = i;
    }

    for(int i = 1; i <= N; i++) {
        a[ans[i]] = i;
    }

    for(int i = 1; i <= N; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
