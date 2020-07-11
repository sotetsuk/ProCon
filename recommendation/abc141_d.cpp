#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M; cin >> N >> M;
    priority_queue<ll> pq;
    for (int i = 0; i < N; ++i) {
        ll a; cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < M; ++i) {
        ll highest = pq.top(); pq.pop();
        pq.push(highest / 2);
    }
    ll min_sum = 0;
    while (!pq.empty()) {
        min_sum += pq.top(); pq.pop();
    }
    cout << min_sum << endl;
    return 0;
}
