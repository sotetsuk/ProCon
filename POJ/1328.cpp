#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

const int max_n = 1000;
int x, y;
int n, r;
typedef pair<int, int> cords;

int solve(int n, int r, int c) {
    // input
    vector<cords> v;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(cords(x, y));
    }

    // sort
    sort(v.begin(), v.end());

    // greedy
    int i = 0;
    int count = 0;
    while(true) {
        if(i == v.size()-1) {
            if(v[i].second <= r) {
                count++;
                break;
            } else {
                count = -1;
                break;
            }
        } else if(i >= v.size()) {
            break;
        } else {
            if(v[i].second <= r) {
                count++;
                int x_i = v[i].first;
                int y_i = v[i].second;
                double p = x_i + sqrt(r*r - y_i*y_i);
                int m = i+1;
                while(true) {
                    int x_next = v[m].first;
                    int y_next = v[m].second;
                    if(x_next < p) {
                        if(y_next <= r) {
                            p = min(p, x_next + sqrt(r*r - y_next*y_next));
                            m++;
                            continue;
                        } else {
                            count = -1;
                            break;
                        }
                    } else {
                        double q = sqrt((x_next-p)*(x_next-p) + y_next*y_next);
                        if(q <= r) {
                            m++;
                            continue;
                        } else {
                            i = m;
                            break;
                        }
                    }
                }
            } else {
                count = -1;
                break;
            }
        }
    }

    cout << "Case " << c << ": " << count << endl;
    return 0;
}

int main() {
    int c = 1;
    while(true) {
        cin >> n >> r;
        if(n == 0 && r == 0) {
            break;
        } else {
            solve(n, r, c);
        }
        c++;
    }

    return 0;
}
