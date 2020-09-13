#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool judge(const unordered_map<ll, ll> &cntA, const unordered_map<ll, ll> &cntB, ll N) {
    for (const auto &[k, v]: cntA) {
        if (cntB.find(k) == cntB.end()) continue;
        if (v > N - cntB.at(k)) return false;
    }
    return true;
}

bool dfs(unordered_map<ll, ll> &cntA, unordered_map<ll, ll> &cntB, vector<ll> &v, ll N) {
    if (cntA.empty() || cntB.empty()) return true;
    if (!judge(cntA, cntB, N)) return false;
    for (const auto &[ka, va]: cntA) {
        for (const auto &[kb, vb]: cntB) {
            if (ka == kb) continue;
            cntA[ka]--;
            cntB[kb]--;
            v.push_back(kb);
            bool ok = dfs(cntA, cntB, v, N);
            if (ok) return true;
            v.pop_back();
            cntA[ka]++;
            cntB[kb]++;
        }
    }
    return false;
}

int main() {
    ll N; cin >> N;
    vector<ll> A(N); for (int i = 0; i < N; ++i) cin >> A[i];
    vector<ll> B(N); for (int i = 0; i < N; ++i) cin >> B[i];
    unordered_map<ll, ll> cntA;
    unordered_map<ll, ll> cntB;
    for (auto a: A) cntA[a]++;
    for (auto b: B) cntB[b]++;
    vector<ll> v;
    bool ok = dfs(cntA, cntB, v, N);
    if (ok) {
        cout << "Yes" << endl;
        for (auto e: v) {
            cout << e << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
