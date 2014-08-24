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

char output[4][7] = {{'x', ' ', 'x', ' ', 'x', ' ', 'x'},
                     {' ', 'x', ' ', 'x', ' ', 'x', ' '},
                     {' ', ' ', 'x', ' ', 'x', ' ', ' '},
                     {' ', ' ', ' ', 'x', ' ', ' ', ' '}};

int dic1[10] = {0, 3, 2, 2, 1, 1, 1, 0, 0, 0};
int dic2[10] = {6, 3, 2, 4, 1, 3, 5, 0, 2, 4};


int a, b;
int p[10], q[10];

int main() {
    cin >> a >> b;

    for(int i = 0; i < 10;i ++) {
        p[i] = -1; q[i] = -1;
    }

    for(int i = 0; i < a; i++) {
        cin >> p[i];
    }

    for(int i = 0; i < b; i++) {
        cin >> q[i];
    }

    for(int i = 0; i < 10; i++) {
        if(p[i] != -1) {
            output[dic1[p[i]]][dic2[p[i]]] = '.';
        }
        if(q[i] != -1) {
            output[dic1[q[i]]][dic2[q[i]]] = 'o';
        }

    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 7; j++) {
            cout << output[i][j];
        }
        cout << endl;
    }


    return 0;
}
