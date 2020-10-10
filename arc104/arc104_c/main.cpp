#include <bits/stdc++.h>
using namespace std;
using ll = long long;


string solve(int N, const vector<int>& A, const vector<int>& B) {
    vector<int> v(2 * N, -1);
    unordered_set<int> observed;
    for (int i = 0; i < N; ++i) {
        if (A[i] != -1 && observed.count(A[i])) return "No";
        if (B[i] != -1 && observed.count(B[i])) return "No";
        if (A[i] != -1) observed.insert(A[i]);
        if (B[i] != -1) observed.insert(B[i]);
        if (A[i] == -1 && B[i] == 0) return "No";
        if (A[i] == 2 * N - 1 && B[i] == -1) return "No";
        if (A[i] == -1 || B[i] == -1) continue;
        if (A[i] >= B[i]) return "No" ;
        int c = B[i] - A[i] - 1;
        for (int j = A[i]; j < B[i]; ++j) {
            if (v[j] != -1 && v[j] != c) {
                return "No";
            }
            v[j] = c;
        }
    }
    for (int i = 0; i < N; ++i) {
        int a = A[i]; int b = B[i];
        if (a != -1 && b != -1) continue;
        if (a == -1 && b == -1) continue;
        if (a == -1) {
            if (b == 0) {
                return "No";
            }
            int c = v[b - 1];
            if (c == -1) continue;
            for (int j = b - 1; b - j <= c; --j) {
                if (j < 0 || v[j] != c) {
                    return "No";
                }
            }
        } else {  // b == -1
            if (a == 2 * N - 1) return "No";
            int c = v[a];
            if (c == -1) continue;
            for (int j = a; j < a + c; ++j) {
                if (v[j] != c) {
                    return "No";
                }
            }
        }
    }
    return "Yes";
}

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        if (A[i] != -1) A[i]--;
        if (B[i] != -1) B[i]--;
    }
    cout << solve(N, A, B) << endl;
    return 0;
}
