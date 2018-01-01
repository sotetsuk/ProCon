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

const int MAX_N = 200005;
queue<int> q;
int N, C;
int v[MAX_N], s[MAX_N], t[MAX_N], c[MAX_N], total[MAX_N];

int main() {
  cin >> N >> C;

  for(int i = 0; i < N; i ++) {
    cin >> s[i] >> t[i] >> c[i];
  }

  for(int i = 1; i <= C; i++) {
    for(int j = 0; j < MAX_N; j++) {
      v[j] = 0;
    }

    for(int j = 0; j < N; j++) {
      if(i == c[j]) {
        v[s[j] * 2 - 1] += 1;
        v[t[j] * 2] -= 1;
      }
    }

    for(int j = 0; j < MAX_N; j++) {
      v[j + 1] += v[j];
      if(v[j] > 0)  {
        total[j] += 1;
      }
    }
  }

  int M = 0;
  for(int i = 0; i < MAX_N; i ++) {
    M = max(total[i], M);
  }

  // for(int i = 0; i< 25; i++) {
  //   cout << i << " " << v[i] << endl;
  // }

  cout << M << endl;

  return 0;
}
