#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, K;
vector<ll> A, B;
ll cnt = 0;
int i = 0, j = 0;

bool rmA() {
    ll t = A[i]; ++i;
    if (K - t < 0) return false;
    ++cnt; K -= t;
    return true;
}
bool rmB() {
    ll t = B[j]; ++j;
    if (K - t < 0) return false;
    ++cnt; K -= t;
    return true;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        ll a; cin >> a; A.push_back(a);
    }
    for (int i = 0; i < M; ++i) {
        ll b; cin >> b; B.push_back(b);
    }
    while (!(i >= N && j >= M) && K >= 0) {
        if (i >= N) {
            if (!rmB()) break;
            continue;
        }
        if (j >= N) {
            if (!rmA()) break;
            continue;
        }
        if (A[i] == B[i]) {
            int i0 = i, j0 = j;
            while (i0 < N && j0 < M && A[i0] == B[j0]) {
                ++i0;
                ++j0;
            }
            if (i0 < N && j0 < M) {
                if (A[i0] < B[j0]) {
                    while (i != i0) {
                        if (!rmA()) break;
                    }
                } else {
                    while (j != j0) {
                        if (!rmB()) break;
                    }
                }
            } else {
                if (i0 >= N) {
                    while (j != j0) {
                        if (!rmB()) break;
                    }
                    continue;
                } else {
                    while (i != i0) {
                        if (!rmA()) break;
                    }
                }
            }
       } else {
            if (A[i] < B[i]) {
                if (!rmA()) break;
            } else {
                if (!rmB()) break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
