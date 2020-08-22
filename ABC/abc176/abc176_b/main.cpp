#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::string s;
    cin >> s;
    ll sum = 0;
    for (char c: s) {
        sum += c - '0';
    }
    if (sum % 9 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
