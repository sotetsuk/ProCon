#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a; A.push_back(a);
    }
    for (int k = 0; k < K; ++k) {
        bool updated = false;
        vector<int> S(N, 0);
        for (int i = 0; i < N; ++i) {
            int a = A[i];
            S[max(i - a, 0)]++;
            if (i + a + 1 < N) S[i + a + 1]--;
        }
        for (int i = 0; i < N; ++i) {
            if (i - 1 >= 0) S[i] += S[i - 1];
            if (A[i] != S[i]) updated = true;
            A[i] = S[i];
        }
        if (!updated) break;
    }
    for (auto &a: A) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
