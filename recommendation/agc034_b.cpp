#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    int n = s.size();
    ll num_contiguous_a = 0;
    ll num_op = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            num_contiguous_a++;
        } else if (s[i] == 'B'){
            if (i + 1 < n && s[i+1] == 'C') {
                num_op += num_contiguous_a;
                ++i;
            } else {
                num_contiguous_a = 0;
            }
        } else {
            num_contiguous_a = 0;
        }
    }
    cout << num_op << endl;
    return 0;
}
