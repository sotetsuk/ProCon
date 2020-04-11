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
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = 0;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                int c = 0;
                for (int l = 0; l < s.size(); ++l) {
                    if (c == 0 && s[l] - '0' == i) {
                        ++c;
                        continue;
                    }
                    if (c == 1 && s[l] - '0' == j) {
                        ++c;
                        continue;
                    }
                    if (c == 2 && s[l] - '0' == k) {
                        ++ans;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
