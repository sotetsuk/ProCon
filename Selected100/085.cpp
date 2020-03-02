//
// Created by Sotetsu KOYAMADA on 2020/03/02.
//

#include <vector>
#include <iostream>

struct UnionFind
{
    std::vector<int> parents;
    UnionFind(int n) : parents(n) { for (int i = 0; i < n; ++i) parents[i] = i; }
    int root(int i) { return i == parents[i] ? i : root(parents[i]); }
    bool same(int i, int j) { return root(i) == root(j); }
    void unite(int i, int j) {
        if (same(i, j)) return;
        parents[root(i)] = root(j);
    }
};


int main()
{
    int n, q, c, x, y;
    std::cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < q; ++i) {
        std::cin >> c >> x >> y;
        if (c == 0) {
            uf.unite(x, y);
        } else {
            if (uf.same(x, y)) {
                std::cout << 1 << std::endl;
            } else {
                std::cout << 0 << std::endl;
            }
        }
    }
    return 0;
}
