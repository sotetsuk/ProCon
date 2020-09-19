#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1000005;
std::vector<ll> num_divisor(MAX_N, 0);

void init_num_divisor() {
    for (int i = 1; i < MAX_N; ++i) {
        for (int j = i; j < MAX_N; j += i) {
            num_divisor[j]++;
        }
    }
}

int main() {
    init_num_divisor();
    int N; cin >> N;
    ll cnt = 0;
    for (int c = 1; c < N; ++c) cnt += num_divisor[c];
    cout << cnt << endl;
    return 0;
}
