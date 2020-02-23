#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long long int N;
    cin >> N;

    if(N == 1) {
        cout << "Deficient" << endl;
        return 0;
    }

    long long int n = 2, m = N, count = 1;
    while(n < m && n <= sqrt(N)) {
        if(N % n == 0) {
            m = N / n;
            count += n + m;
            if(n == m) count -= n;
        }
        n++;
    }

    if(count == N) {
        cout << "Perfect" << endl;
    } else if(count < N) {
        cout << "Deficient" << endl;
    } else {
        cout << "Abundant" << endl;
    }
    return 0;
}
