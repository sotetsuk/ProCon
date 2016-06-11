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

struct point {
    int x;
    int y;
};

struct line {
    point a;
    point b;
};

double det(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

// l1 からみて，l2の2端点が左右に反対にあるかチェック
bool _intersect(line& l1, line& l2) {
    double x1, y1, x2, y2;

    x1 = l1.b.x - l1.a.x; y1 = l1.b.y - l1.a.y;
    x2 = l2.a.x - l1.a.x; y2 = l2.a.y - l1.a.y;
    double signed_s1 = det(x1, y1, x2, y2);

    x1 = l1.b.x - l1.a.x; y1 = l1.b.y - l1.a.y;
    x2 = l2.b.x - l1.a.x; y2 = l2.b.y - l1.a.y;
    double signed_s2 = det(x1, y1, x2, y2);

    if (signed_s1 * signed_s2 < 0) {
        return true;
    } else {
        return false;
    }
}

bool intersect(line &l1, line& l2) {
    if (_intersect(l1, l2) && _intersect(l2, l1)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    double ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    point a, b;
    a.x = ax; a.y = ay;
    b.x = bx; b.y = by;
    line l;
    l.a = a; l.b = b;

    int N;
    cin >> N;
    int c = 0;
    int x0; int y0;
    line m;
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            cin >> x0 >> y0;
            ax = x0; ay = y0;
        }
        cin >> bx >> by;
        a.x = ax; a.y = ay;
        b.x = bx; b.y = by;
        m.a = a; m.b = b;
        if(intersect(l, m)) c++;
        ax = bx; ay = by;
    }
    bx = x0; by = y0;
    a.x = ax; a.y = ay;
    b.x = bx; b.y = by;
    m.a = a; m.b = b;
    if(intersect(l, m)) c++;

    cout << c/2 + 1 << endl;

    return 0;
}
