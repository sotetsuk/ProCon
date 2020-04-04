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
    queue<ll> q;
    unordered_set<ll> s;
    for (ll i = 1; i <= 9; ++i) {
        q.push(i);
    }

    ll K;
    cin >> K;
    while(s.size() < 5 * K && !q.empty()) {
        auto e = q.front(); q.pop();
        // cout << e << endl;
        s.insert(e);
        auto d = e % 10;
        if (d - 1 >= 0) q.push(e * 10 + d - 1);
        q.push(e * 10 + d);
        if (d + 1 <= 9) q.push(e * 10 + d + 1);
    }


    vector<ll> v(s.begin(), s.end());
    sort(v.begin(), v.end());
    // for (int i = 0; i < 100; ++i) {
    //     cout << i + 1 << " " << v[i] << endl;
    // }
    cout << v[K-1] << endl;
    return 0;
}
