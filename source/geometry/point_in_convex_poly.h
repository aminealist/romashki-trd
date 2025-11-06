bool point_in_polygon(pt p) {
    if (!is_dot_in_angle(a[0], a[1], a[n - 1], p))
        return false;
    int l = 1;
    int r = n;
    while (r - l > 1) {
        int m = (r + l) >> 1;
        ll cp = pt(a[0], a[m]) ^ pt(a[0], p);
        if (cp > 0) {
            l = m;
        } else {
            r = m;
        }
    }
    return sign(pt(a[l], a[l + 1]) ^ pt(a[l], p)) >= 0;
}