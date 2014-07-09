// O(E*log(V))

struct edge {int u, v, cost;};

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.csot;
}

edge es[MAX_E];
sort(es, es + E, comp);
