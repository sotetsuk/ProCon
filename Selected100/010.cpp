#include <iostream>

using namespace std;

const int N = 100000;

int main() {
    int n, q, t;
    bool a[N];
    for (int i = 0; i < N; ++i) a[i] = false;
    a[0] = true;
    cin >> n;
    // for (int i = 0; i < 10; ++i) {
    //     cout << i << ": " << a[i] << endl;
    // }
    for (int i = 0; i < n; ++i) {
        cin >> t;
        for (int j = N - 1; j >= 0; --j) {
            if (j - t >= 0 && a[j - t]) a[j] = true;
        }
    }
    // for (int i = 0; i < 10; ++i) {
    //     cout << i << ": " << a[i] << endl;
    // }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> t;
        cout << (a[t] ? "yes" : "no") << endl;
    }

    return 0;
}
