#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    if (s == "RRS") {
        cout << 2 << endl;
        return 0;
    } else if  (s == "SRR") {
        cout << 2 << endl;
        return 0;
    } if (s == "RRR") {
        cout << 3 << endl;
        return 0;
    } if (s == "RSR") {
        cout << 1 << endl;
        return 0;
    } else if (count_if(s.begin(), s.end(), [](char c){ return c == 'R'; }) == 1) {
        cout << 1 << endl;
        return 0;
    } else {
        cout << 0 << endl;
        return 0;
    }
    return 0;
}
