vector<pt> graham(vector<pt> points) {
    pt st = points[0];
    for (auto p : points) {
        if ((p.y < st.y) || (p.y == st.y && p.x < st.x))
            st = p;
    }
    for (auto &el : points)
        el = el - st;
    sort(points.begin(), points.end(), polar_angle_cmp);
    for (auto &el : points)
        el = el + st;
    vector<pt> hull;
    for (auto p : points) {
        while (hull.size() >= 2) {
            pt cur = pt(hull[hull.size() - 2], hull.back());
            pt cond = pt(hull.back(), p);
            ll cp = cur ^ cond;
            if (cp > 0)
                break;
            hull.pop_back();
        }
        hull.push_back(p);
    }
    return hull;
}