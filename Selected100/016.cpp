#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

// namespace
using namespace std;
namespace mp = boost::multiprecision;

// types
using pii = pair<int, int>;
using ll = long long int;
using ld = long double;
using mpi = mp::cpp_int;
using mpf = mp::number<mp::cpp_dec_float<1024>>;

// consts
int MOD = 1000000007;  // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a


int main() {
    int n, t;
    cin >> n;
    vector<int> p, q, r;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        p.emplace_back(t);
    }
    for (int i = 0; i < n; ++i) {
        cin >> t;
        q.emplace_back(t);
    }
    for (int i = 1; i <= n; ++i) r.emplace_back(i);

    int a, b, i = 1;
    do {
        bool ok = true;
        for (int k = 0; k < n; ++k) {
            if (p[k] != r[k]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            a = i;
        }
        ok = true;
        for (int k = 0; k < n; ++k) {
            if (q[k] != r[k]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            b = i;
        }
        ++i;
    } while (next_permutation(r.begin(), r.end()));
    cout << abs(a - b) << endl;
    return 0;
}
