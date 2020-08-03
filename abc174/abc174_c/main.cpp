#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main() {
    ll K; cin >> K;
    ll N = 7;
    for (int i = 1; i < 1e8; ++i) {
        if (N % K == 0) {
            cout << i << endl;
            return 0;
        }
        N %= K;
        N = N * 10 + 7;
    }
    cout << -1 << endl;
    return 0;
}
