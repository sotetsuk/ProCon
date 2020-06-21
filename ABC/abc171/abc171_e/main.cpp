#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    int s = 0;
    for (int i = 0 ; i < N; ++i) {
        cin >> A[i];
        s ^= A[i];
    }
    for (int i = 0; i < N; ++i) {
        cout << (int)(s ^ A[i]) << " ";
    }
    cout << endl;
    return 0;
}
