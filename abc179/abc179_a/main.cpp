#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    if (s.back() == 's') s += "es";
    else s += "s";
    cout << s << endl;
    return 0;
}
