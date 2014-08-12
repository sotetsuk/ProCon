#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

const int MAX_P = 1000000010;

int p, n;

bool is_prime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }return n != 1; // n = 1 is exception
}

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
    }
    return res;
}

void solve() {
    if(is_prime(p)) {
        cout << "no" << endl;
        return;
    } else {
        if(mod_pow(n, p, p) == n) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return;
}

int main() {
    while(true) {
        cin >> p >> n;
        if(p || n) {
            solve();
        } else {
            break;
        }
    }

    return 0;
}
