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

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll t = numeric_limits<int>::max();
    t = min(t, a * x + b * y);
    t = x < y ? min(t, 2 * c * y) : min(t, 2 * c * x);
    ll s = 0;
    if (a + b > 2 * c) {
        while (min(x, y) > 0) {
            s += 2 * c;
            --x;
            --y;
        }
    }
    s += a * x;
    s += b * y;
    t = min(t, s);
    cout << t << endl;
    return 0;
}
