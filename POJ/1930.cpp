#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

typedef pair<int, int> pii;
typedef long long int ll;
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

ll x;

char tmp[101];
string s;
// string s(100, ' ');

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve(int d) {
    ll p = 1;
    for(int i = 0; i < s.size(); i++) {
        p *= 10;
    }
    ll g = gcd(x, p);

    if(d) {
        x = x/g*d; p = p/g*9;
        cout << x << "/" << p << endl;
    } else {
        cout << x/g << "/" << p/g << endl;
    }
    return;
}

int main() {
    int a;
    while(true) {
        stringstream ss;
        // cin >> s;
        scanf("%100s", tmp);
        s = tmp;
        // scanf("%*s", &s[0], s.size());
        if(s.size() == 1) break;
        s = s.substr(2, s.size()-5);
        ss << s;
        ss >> x;

        // cout << "num: " << x << endl; // debug
        if(x%10 == 0) {
            solve(0);
        } else if(x%10 == 9) {
            x += 1;
            solve(0);

        } else {
            long double y = (long double)x;
            int d = x%10;
            y = y*9/d;
            while(y - (ll)y > 0.0) {
                y *= 10;
            }
            x = (ll)y;
            x += 1;
            solve(d);
        }
    }

    return 0;
}
