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

const int MAX_N = 15000;
int arr[MAX_N+10][MAX_N+10];

int main() {
    int A;
    cin >> A;

    bool flag = false;
    arr[0][0] = 1;
    for(int i = 1; i < MAX_N; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
            if(arr[i][j] == A) {
                // cout << endl; //
                cout << i+1 << " " << j+1 << endl;
                flag = true;
            }
            if(flag) break;
            // cout << arr[i][j] << " ";//
        }
        // cout << endl;//
        if(flag) break;
    }

    if(!flag) {
        cout << "-1 -1" << endl;
    }

    return 0;
}
