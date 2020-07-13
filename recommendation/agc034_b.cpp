#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    int num_contiguous_a = 0;
    int num_op = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') num_contiguous_a++;
        else num_contiguous_a = 0;
        if (i + 2 < s.size() && s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            num_op += num_contiguous_a;
            num_contiguous_a = 0;
            s[i+1] = 'C';
            s[i+2] = 'A';
        }
    }
    cout << num_op << endl;
    return 0;
}
