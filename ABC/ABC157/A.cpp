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

int N;

int main() {
    cin >> N;
    if (N % 2 == 0) {
        cout << N / 2 << endl;
    } else {
        cout << N / 2 + 1 << endl;
    }
    return 0;
}
