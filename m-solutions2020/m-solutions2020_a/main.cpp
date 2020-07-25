#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int X; cin >> X;
    int Y = -1;
    if (X < 600) Y = 8;
    else if (X < 800) Y = 7;
    else if (X < 1000) Y = 6;
    else if (X < 1200) Y = 5;
    else if (X < 1400) Y = 4;
    else if (X < 1600) Y = 3;
    else if (X < 1800) Y = 2;
    else if (X < 2000) Y = 1;
    cout << Y << endl;
    return 0;
}
