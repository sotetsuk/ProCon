#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    int s = accumulate(A.begin(), A.begin() + K, 0);
    cout << s << endl;
    return 0;
}
