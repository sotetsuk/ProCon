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

int N, K;

int main() {
    cin >> N >> K;

    priority_queue<pii> v;
    int t;
    for(int i = 0; i < K; i++) {
        cin >> t;
        v.push(pii(t, i+1));
    }

    for(int i = K; i < N; i++) {
        pii g = v.top();
        cout << g.second << endl;

        cin >> t;
        if(g.first > t) {
            v.pop();
            v.push(pii(t, i+1));
        }
    }
    pii g = v.top();
    cout << g.second << endl;

    return 0;
}
