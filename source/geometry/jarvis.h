vector<pt> jarvis(vector<pt> points) {
    pt st = points[0];
    for (auto p : points) {
        if ((p.x < st.x) || (p.x == st.x && p.y < st.y)) {
            st = p;
        }
    }
    vector<pt> hull = {st};
    while (true) {
        pt par = hull.back();
        pt next = hull.back();
        for (auto p : points) {
            ll cp = pt(par, next) ^ pt(par, p);
            ll manh1 = pt(par, next).manhat_len();
            ll manh2 = pt(par, p).manhat_len();
            if (cp < 0) {
                next = p;
            } else if (cp == 0 && manh1 < manh2) {
                next = p;
            }
        }
        if (next == hull[0])
            break;
        hull.push_back(next);
    }
    return hull;
}