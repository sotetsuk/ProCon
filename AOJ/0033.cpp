#include <iostream>
#include <vector>
using namespace std;

int N;
int balls[15];

int solve() {
    vector<int> A, B;
    for(int i = 0; i < 10; i++) {
        if(i == 0) {
            A.push_back(balls[i]);
        } else {
            if(B.size() == 0) {
                if(A[A.size()-1] > balls[i]) {
                    B.push_back(balls[i]);
                } else {
                    A.push_back(balls[i]);
                }
            } else {
                if(A[A.size()-1] < balls[i] && B[B.size()-1] < balls[i]) {
                    if(A[A.size()-1] > B[B.size()-1]) {
                        A.push_back(balls[i]);
                    } else {
                        B.push_back(balls[i]);
                    }
                } else if(A[A.size()-1] < balls[i] && B[B.size()-1] > balls[i]) {
                    A.push_back(balls[i]);
                } else if(A[A.size()-1] > balls[i] && B[B.size()-1] < balls[i]) {
                    B.push_back(balls[i]);
                } else {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> balls[j];
        }
        solve();
    }

    return 0;
}
