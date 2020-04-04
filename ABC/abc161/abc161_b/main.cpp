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
    int N, M, t, s, a;
    s = 0; a = 0;
    vector<int> v;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        v.push_back(t);
        s += t;
    }
    for (auto e: v) {
        if (e * 4 * M >= s) ++a;
    }
    if (a >= M) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
