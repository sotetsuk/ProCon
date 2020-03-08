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
#include <sstream>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

int main() {
    string s;
    cin >> s;
    if (s.size() % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0 && s[i] != 'h') {
            cout << "No" << endl;
            return 0;
        }
        if (i % 2 == 1 && s[i] != 'i') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

