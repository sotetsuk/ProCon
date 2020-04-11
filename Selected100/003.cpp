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
    string s;
    cin >> s;
    int cnt = 0, ans = 0;
    for (auto c: s) {
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            ++cnt;
        } else {
            ans = max(cnt, ans);
            cnt = 0;
        }
    }
    ans = max(cnt, ans);
    cout << ans << endl;
    return 0;
}
