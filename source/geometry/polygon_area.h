ld polygon_area(vector<pt> points) {
    ll ans = 0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        ans += points[i] ^ points[(i + 1) % n];
    }
    return abs(ans) * 0.5;
}
