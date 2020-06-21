#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    string s = "";
    while (N != 0) {
        --N;
        ll x = N % 26;
        char c = 'a' + x;
        s += c;
        N /= 26;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
