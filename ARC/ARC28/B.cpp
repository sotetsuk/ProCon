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

    vector<pii> v;
    int t;
    for(int i = 0; i < K; i++) {
        cin >> t;
        v.push_back(pii(t, i+1));
    }
    sort(v.begin(), v.end());
    cout << v[K-1].second << endl;

    for(int i = K; i < N; i++) {
        cin >> t;
        if(v[K-1].first > t) {
            v[K-1].first = t;
            v[K-1].second = i+1;
            sort(v.begin(), v.end());
        }
        cout << v[K-1].second << endl;
    }

    return 0;
}
