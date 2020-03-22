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

string str;

bool isP(string s, int i, int j) {
    for (int a = 0, b = j - 1; a < b; ++a, --b) {
        // cout << a << " " << s[a] << " " << b << " " << s[b] << endl;
        if (s[a] != s[b]) return false;
    }
    return true;
}

int main() {
    cin >> str;
    int n = str.size();
    if (isP(str, 0, n) && isP(str, 1, (n-1)/2) && isP(str, (n+3)/2, n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
