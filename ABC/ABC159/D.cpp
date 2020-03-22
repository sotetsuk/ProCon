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

int N;
int main() {
    vector<int> v(200005);
    map<int, ll> m;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        ++m[v[i]];
    }
    ll c = 0;
    for (auto & kv : m) {
        // cout << kv.first << " " <<  kv.second << endl;
        c += kv.second * (kv.second - 1) / 2;
    }
    for (int k = 0; k < N; ++k) {
        int n = m[v[k]];
        // cout << v[k] << " " << c << " " <<  (n * (n - 1) / 2) << " " << ((n - 1) * (n - 2) / 2) << endl;
        if (n == 1)  {
            cout << c << endl;
        } else {
            cout << c - (n * (n - 1) / 2) + ((n - 1) * (n - 2) / 2) << endl;
        }
    }
    return 0;
}
