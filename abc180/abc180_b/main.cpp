#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<long double> v(N); for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    std::cout << std::setprecision(10);

    long double m = 0;
    for (const auto &e: v) {
        m += abs(e);
    }
    cout << m << endl;

    long double u = 0;
    for (const long double &e: v) {
        u += abs(e) * abs(e);
    }
    cout << sqrt(u) << endl;

    long double c = 0;
    for (const auto &e: v) {
        c = max(c, abs(e));
    }
    cout << c << endl;

    return 0;
}
