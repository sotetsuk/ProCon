#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 100000;
const int MAX_A = 100000;
int N;
int A[MAX_N+5];
int c[MAX_A+5];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int count = 0;
    int l = 0;
    for(int r = 0; r < N; r++) {
        c[A[r]]++;
        while(c[A[r]] > 1) {
            c[A[l]]--;
            l++;
        }
        count = max(count, r-l+1);
    }

    cout << count << endl;

    return 0;
}
