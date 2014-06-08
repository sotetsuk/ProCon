#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int n, v;
int a, b;

int main() {
    vector<P> v1;
    vector<P> v2;

    cin >> n >> v;
    for(int i = 0; i < n; i ++) {
        cin >> a >> b;
        v1.push_back(P(a, b));
    }

    sort(v1.begin(), v1.end());

    for(int i = 0; i < v1.size(); i++) {
        if(i == 0) {
            v2.push_back(v1[i]);
        } else {
            if(v1[i].first == v2[v2.size()-1].first) {
                v2[v2.size()-1].second += v1[i].second;
            } else {
                v2.push_back(v1[i]);
            }
        }
    }

    int c = 0;
    int rest = 0;
    int a_bef = 0;

    for(int i = 0; i < v2.size(); i++) {
        a = v2[i].first;
        b = v2[i].second;
        if(a_bef != a-1) {
            c += min(rest, v);
            rest = 0;
        }

        int cap = v;
        if(cap <= rest) {
            c += cap;
            rest = b;
        } else {
            cap -= rest;
            c += rest;
            c += min(b, cap);
            rest = max(0, b-cap);
        }
        a_bef = a;
    }
    c += min(rest, v);

    cout << c << endl;

    return 0;
}
