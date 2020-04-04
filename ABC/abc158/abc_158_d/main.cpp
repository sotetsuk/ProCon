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
    int q, t, f;
    char c;
    vector<char> fr;
    vector<char> bc;
    bool rev = false;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> t;
        if (t == 1) {
            rev = !rev;
            continue;
        }
        cin >> f;
        cin >> c;
        if (f == 1) {
            if (rev) {
                bc.push_back(c);
            } else {
                fr.push_back(c);
            }
        } else {
            if (rev) {
                fr.push_back(c);
            } else {
                bc.push_back(c);
            }
        }
    }
    // cout << "start" << endl;
    for (auto e : bc) {
        // cout << e << endl;
        s += e;
    }
    // cout << "rev" << endl;
    reverse(s.begin(), s.end());
    for (auto e : fr) {
        // cout << e << endl;
        s += e;
    }
    // cout << "end" << endl;
    if (!rev) reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
