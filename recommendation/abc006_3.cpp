#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    for (int num2 = 0; num2 <= N; ++num2) {
        int target = M - 2 * num2;
        if (target < 0) continue;
        int num4l = 0, num4r = N - num2 + 1;
        while (num4r - num4l > 1) {
            int num4m = num4l + (num4r - num4l) / 2;
            int num3 = N - num2 - num4m;
            if (3 * num3 + 4 * num4m <= target) num4l = num4m;
            else num4r = num4m;
        }
        if (int num3 = N - num2 - num4l; 3 * num3 + 4 * num4l == target) {
            cout << num2 << " " << num3 << " " << num4l << endl;
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}
