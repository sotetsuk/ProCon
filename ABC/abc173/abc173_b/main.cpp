#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    unordered_map<string, int> m;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        m[s]++;
    }
    cout << "AC" << " x " <<  m["AC"] << endl;
    cout << "WA" << " x " <<  m["WA"] << endl;
    cout << "TLE" << " x " <<  m["TLE"] << endl;
    cout << "RE" << " x " <<  m["RE"] << endl;
    return 0;
}
