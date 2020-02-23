#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    if(N <= 5) {
        ans = N * B;
    } else {
        ans = 5 * B + (N - 5) * A;
    }
    cout << ans << endl;
    return 0;
}
