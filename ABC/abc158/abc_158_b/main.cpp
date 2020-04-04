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

ll n, a, b;

int main() {
    cin >> n >> a >> b;
    if (a == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (b == 0) {
        cout << n << endl;
        return 0;
    }
    ll x = n / (a + b);
    ll y = min(n % (a + b), a);
    cout << x * a + y << endl;
    return 0;
}
