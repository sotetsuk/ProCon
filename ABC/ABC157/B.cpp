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

int A[4][4];
int B[4][4];
int N;

int main() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> A[i][j];
            B[i][j] = 0;
        }
    }
    cin >> N;
    int b;
    for (int n = 0; n < N; ++n) {
        cin >> b;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (b == A[i][j]) {
                    B[i][j] = 1;
                }
            }
        }
    }

    bool flag = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (B[i][j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        } else {
            flag = true;
        }
    }

    flag = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (B[j][i] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        } else {
            flag = true;
        }
    }

    flag = true;
    for (int i = 0; i < 3; ++i) {
            if (B[i][i] == 0) {
                flag = false;
                break;
            }
    }
    if (flag) {
        cout << "Yes" << endl;
        return 0;
    }

    flag = true;
    for (int i = 0; i < 3; ++i) {
        if (B[i][2-i] == 0) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}
