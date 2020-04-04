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

int A, B;

int main() {
    cin >> A >> B;
    auto x = B * 10;
    auto y = (B + 1) * 10;
    for (int i = x; i < y; ++i) {
        if (static_cast<int>(i * 0.08) == A) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
