#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> p(N); for (int i = 0; i < N; ++i) cin >> p[i];
    vector<bool> used(N + 1, false);
    int curr = 0;
    for (int i = 0; i < N; ++i) {
        if (p[i] <= N) used[p[i]] = true;
        while(used[curr]) ++curr;
        cout << curr << endl;
    }
    return 0;
}
