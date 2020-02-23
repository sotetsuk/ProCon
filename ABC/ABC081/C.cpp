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

const int N_MAX = 200005;
int N, K;
int A[N_MAX];
map<int, int> m;

struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
};

int main() {
    int a;
    int k = 0;
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        A[i] = a;
        if(m.find(A[i]) == m.end()) {
            m[A[i]] = 1;
            k++;
        } else {
            m[A[i]] += 1;
        }
    }

    vector<pair<int, int> > v;
    for(pair<int, int> p:m) {
        v.push_back(p);
    }

    sort(v.begin(), v.end(), sort_pred());

    int count = 0;
    for(pair<int, int> p:v) {
        if (k <= K) break;

        count += p.second;
        k--;
    }

    cout << count << endl;

    return 0;
}