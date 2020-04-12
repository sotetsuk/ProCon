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
    int N;
    string s;
    cin >> N;
    cin >> s;
    vector<int> R(N + 5, 0);
    vector<int> G(N + 5, 0);
    vector<int> B(N + 5, 0);
    int num_r = 0;
    int num_g = 0;
    int num_b = 0;
    for (int i = N - 1; i >= 0; --i) {
        char c = s[i];
        if (c == 'R') {
            num_r++;
        } else if (c == 'G') {
            num_g++;
        } else {
            num_b++;
        }
        R[i] = num_r;
        G[i] = num_g;
        B[i] = num_b;
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            if (s[i] == s[j]) continue;
            if (s[i] != 'R' && s[j] != 'R') {
                ans += R[j + 1];
                if (j + (j - i) < N && R[j + 1] > 0 && s[j + (j - i)] == 'R') --ans;
            }
            if (s[i] != 'G' && s[j] != 'G') {
                ans += G[j + 1];
                if (j + (j - i) < N && G[j + 1] > 0 && s[j + (j - i)] == 'G') --ans;
            }
            if (s[i] != 'B' && s[j] != 'B') {
                ans += B[j + 1];
                if (j + (j - i) < N && B[j + 1] > 0 && s[j + (j - i)] == 'B') --ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
