#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A[3], K; cin >> A[0] >> A[1] >> A[2] >> K;
    for (int i = 0; i < K; ++i) {
        if (A[0] >= A[1]) {
            A[1] *= 2;
            continue;
        }
        if (A[1] >= A[2]) {
            A[2] *= 2;
            continue;
        }
    }
    if (A[0] < A[1] && A[1] < A[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
