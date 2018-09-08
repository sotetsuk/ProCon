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

int N = 505;
int H, W, a;
int A[505][505];
int M = 0;
vector<vector<int> > ans;

int main() {
    cin >> H >> W;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a;
            A[i][j] = a;
        }
    }

    for (int i = 0; i < H - 1; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] % 2 == 1) {
                A[i][j]--;
                A[i+1][j]++;
                M++;
                vector<int> v;
                v.push_back(i+1);
                v.push_back(j+1);
                v.push_back(i+2);
                v.push_back(j+1);
                ans.push_back(v);
            }
        }
    }

    int x = H - 1;
    for (int j = 0; j < W - 1; j++) {
        if (A[x][j] % 2 == 1) {
            A[x][j]--;
            A[x][j+1]++;
            M++;
            vector<int> v;
            v.push_back(x+1);
            v.push_back(j+1);
            v.push_back(x+1);
            v.push_back(j+2);
            ans.push_back(v);
        }
    }

    cout << M << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
    }

    return 0;
}