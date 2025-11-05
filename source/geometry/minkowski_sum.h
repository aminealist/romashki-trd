vector<pt> minkowski_sum(vector<vector<pt>> polygons) {
    vector<pt> d;
    pt ms(0, 0);
    for (auto &poly : polygons) {
        pt cs = *min_element(poly.begin(), poly.end(), [&](pt p1, pt p2) {
            return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
        });
        ms = ms + cs;
        int n = poly.size();
        for (int i = 0; i < n; i++) {
            d.push_back(pt(poly[i], poly[(i + 1) % n]));
        }
    }
    sort(d.begin(), d.end(), polar_angle_cmp);
    for (auto &p : d) {
        p = p + ms;
        ms = p;
    }
    return d;
}