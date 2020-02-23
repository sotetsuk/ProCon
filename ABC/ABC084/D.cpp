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

int q, l, r;
const int N = 100005;
int is_prime[N];
int is_similar[N];

void sieve(){
    for(int i = 0; i < N; i++) {
      is_prime[i] = 1;
    }

    is_prime[0] = 0;
    is_prime[1] = 0;

    for(int i = 2; i * i < N; ++i)
        if(is_prime[i])
            for(int j = 2; i * j < N; ++j)
                is_prime[i * j] = 0;
}

void fill_similar() {
  for(int i = 0; i < N; i++) {
    if(is_prime[i] && is_prime[(i + 1) / 2]) {
      is_similar[i] = 1;
    }
  }
}

void inc() {
    int cur = 0;
    for(int i = 0; i < N; i++) {
      if (is_similar[i] == 1) {
        cur = cur + 1;
      }
      is_similar[i] = cur;
    }
}

int main() {
    sieve();
    fill_similar();
    inc();

    cin >> q;
    for(int i = 0; i < q; i++) {
      cin >> l >> r;
      cout << is_similar[r] - is_similar[l - 1] << endl;
    }
    return 0;
}
