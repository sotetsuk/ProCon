#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<double, double> P;

int n;
double p;

vector<P> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p;
        v.push_back(P(p, 1-p));
    }

    if(n == 1) {
        cout << p << endl;
        return 0;
    }

    sort(v.begin(), v.end());


    P ans = P(v.back().first, v.back().second);
    v.pop_back();

    for(int j = 0; j < v.size(); j++) {
        for(int i = j; i < v.size(); i++) {
            P next = P(v[i].first * ans.second + v[i].second * ans.first, v[i].second * ans.second);
            if(next.first > ans.first) {
                ans = next;
            }
        }
    }

    cout << ans.first << endl;

    return 0;
}
