#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    char S, T; cin >> S >> T;
    if (S == 'Y') T += 'A' - 'a';
    cout << T << endl;
    return 0;
}
