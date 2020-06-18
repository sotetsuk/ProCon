#include <bits/stdc++.h>

int main() {
    using namespace std;
    int N, Q; cin >> N >> Q;

    vector<int> A(N), B(N);
    vector<multiset<int>> schools(200005);
    multiset<int> maxs;

    auto DelMax = [&](int school) {
        if (schools[school].empty()) return;
        auto m = schools[school].rbegin();
        auto it = maxs.find(*m);
        if (it != maxs.end()) maxs.erase(it);
    };
    auto AddMax = [&](int school) {
        if (schools[school].empty()) return;
        auto m = schools[school].rbegin();
        maxs.insert(*m);
    };
    auto DelInf = [&](int inf) {
        int school = B[inf];
        DelMax(school);
        schools[school].erase(schools[school].find(A[inf]));
        AddMax(school);
    };
    auto AddInf = [&](int inf, int school){
        DelMax(school);
        B[inf] = school;
        schools[school].insert(A[inf]);
        AddMax(school);
    };

    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i]; B[i]--;
        AddInf(i, B[i]);
    }

    for (int i = 0; i < Q; ++i) {
        int C, D; cin >> C >> D; --C; --D;
        DelInf(C);
        AddInf(C, D);
        cout << *maxs.begin() << endl;
    }
    return 0;
}
