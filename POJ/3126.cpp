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
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

const int MAX_N = 10010;
const int INF = 1000000;
int T, S, G;

int prime[MAX_N];
bool is_prime[MAX_N + 1];

// return the number of primes <= n
int sieve(int n) {
    int p = 0;
    for(int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            for(int j = 2 * i; j <= n;j += i) is_prime[j] = false;
        }
    }
    return p;
}

vector<int> return_digits(int S) {
    vector<int> ret;
    ret.push_back(S/1000);
    ret.push_back((S%1000)/100);
    ret.push_back((S%100)/10);
    ret.push_back(S%10);
    return ret;
}

int main() {
    sieve(10005);

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> S >> G;
        queue<pii> q;
        q.push(pii(S, 0));
        bool dp[10000];
        for(int i = 0; i < 10000; i++) {
            dp[i] = false;
        }
        dp[S] = true;
        if(S == G) {
            cout << 0 << endl;
            continue;
        }
        while(!q.empty()) {
            pii p = q.front(); q.pop();
            int now_num = p.first;
            int n = p.second;
            if(now_num == G) {
                cout << n << endl;
                break;
            }
            vector<int> d = return_digits(now_num);
            int next_num;
            for(int i = 0; i <= 9; i++) {
                next_num = i*1000 + d[1]*100 + d[2]*10 + d[3];
                if(i != 0 && is_prime[next_num] && !dp[next_num]) {
                    q.push(pii(next_num, n+1));
                    dp[next_num] = true;
                }
                next_num = d[0]*1000 + i*100 + d[2]*10 + d[3];
                if(is_prime[next_num] && !dp[next_num]) {
                    q.push(pii(next_num, n+1));
                    dp[next_num] = true;
                }
                next_num = d[0]*1000 + d[1]*100 + i*10 + d[3];
                if(is_prime[next_num] && !dp[next_num]) {
                    q.push(pii(next_num, n+1));
                    dp[next_num] = true;
                }
                next_num = d[0]*1000 + d[1]*100 + d[2]*10 + i;
                if(is_prime[next_num] && !dp[next_num]) {
                    q.push(pii(next_num, n+1));
                    dp[next_num] = true;
                }
            }
        }
    }
    return 0;
}
