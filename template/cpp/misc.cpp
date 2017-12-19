// distance
double distance(int x0, int y0, int x1, int y1) {
    return hypot(x1-x0, y1-y0);
}

double distance(pair<int, int> p0, pair<int, int> p1) {
    return hypot(p1.first-p0.first, p1.second-p0.second);
}
