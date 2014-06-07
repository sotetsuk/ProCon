#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;

const int MAX_N = 10000;
int T, N;
int l[MAX_N+5];
int w[MAX_N+5];

int solve() {
    vector<P> v;
    for(int i = 0; i < N; i++) {
        P p = P(l[i], w[i]);
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}

int main() {
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N;
        cout << "### " << i << endl;
        for(int j = 0; j < N; j ++) {
            cin >> l[j] >> w[j];
        }
            solve();
    }
    return 0;
}
