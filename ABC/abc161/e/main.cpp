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
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

// namespace
using namespace std;
namespace mp = boost::multiprecision;

// types
using pii = pair<int, int>;
using ll = long long int;
using ld = long double;
using mpi = mp::cpp_int;
using mpf = mp::number<mp::cpp_dec_float<1024>>;

shared_ptr<vector<int>> dfs(int i, int K, int C, const vector<int> & blocks, map<pii, shared_ptr<vector<int>>> dp) {
    if (dp.find(make_pair(i, K)) != dp.end()) {
        return nullptr;
    }

    if (i >= blocks.size()) {
        if (K >= 1) {
            return nullptr;
        } else {
            auto v = make_shared<vector<int>>();
            return v;
        }
    }

    shared_ptr<vector<int>> v1, v2;
    v1 = dfs(i + 1, K, C, blocks, dp);
    if (blocks[i] != 0 && K > 0) {
        v2 = dfs(i + max(C + 1, 1), K - 1, C, blocks, dp);
        if (v2 != nullptr) v2->push_back(i+1);
    }

    if (v1 != nullptr && v2 != nullptr){
        auto v = std::make_shared<vector<int>>();
        set_intersection(v1->begin(), v1->end(), v2->begin(), v2->end(), back_inserter(*v));
        dp[make_pair(i, K)] = v;
        return v;
    } else if (v1 != nullptr) {
        dp[make_pair(i, K)] = v1;
        return v1;
    } else if (v2 != nullptr) {
        dp[make_pair(i, K)] = v2;
        return v2;
    } else {
        dp[make_pair(i, K)] = nullptr;
        return nullptr;
    }
}

int main() {
    int N, K, C;
    string S;
    cin >> N >> K >> C;
    cin >> S;

    vector<int> blocks;
    for (auto e : S) {
        if (e == 'o') blocks.push_back(1);
        else blocks.push_back(0);
    }

    map<pii, shared_ptr<vector<int>>> dp;
    auto v = dfs(0, K, C, blocks, dp);

    sort(v->begin(), v->end());
    for (auto e: *v) {
        cout << e << endl;
    }
    return 0;
}
