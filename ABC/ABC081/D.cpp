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

int N, a;
int m;
int idx = 1;

int main() {

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> a;
    if (abs(a) > abs(m)) {
      m = a;
      idx = i;
    }
  }

  cout << 2 * N - 2 << endl;
  for(int i = 1; i <= N; i++) {
    if (i == idx) {
      continue;
    }
    cout << idx << " " << i << endl;
  }

  for(int i = 1; i < N; i++) {
    if (m >= 0) {
      cout << i << " " << i + 1 << endl;
    } else {
      cout << N - i + 1 << " " << N - i << endl;
    }
  }

  return 0;
}
