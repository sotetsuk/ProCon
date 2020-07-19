#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K; cin >> N >> K;
    string S; cin >> S;
    int num_facing = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] != S[i + 1]) ++num_facing;
    }
    num_facing = max(0, num_facing - 2 * K);
    cout << N - 1 - num_facing << endl;
    return 0;
}
