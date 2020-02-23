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

int N, X;
int x[100005];

long long int getEnergy(int start, int m) {
    long long int energy = (m - start + 1) * X;
    energy += m[i]
    int k = 1;
    for (int i = m - 1; i >= start; i++) {
        energy += (x[i] - x[i + 1]) * (k + 1) * (k + 1);
    }
    return energy;
}

int main() {
    cin >> N;
    cin >> X;
    x[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> x[i + 1];
    }

    int curr = 0;
    long long int ans = 0;
    while (curr < N) {
        int m = 1;
        long long int energy = 0;
        int energy = getEnergy(curr + 1, curr + m);
        while (curr + m + 1 <= N && 
        energy + getEnergy(curr + m + 1, curr + m + 1) >= getEnergy(curr + 1, curr + m + 1)) {
            energy = getEnergy(curr + 1, curr + m);
            m++;
        }
        ans += energy;
        curr = m;
    }
    cout << ans << endl;
    return 0;
}