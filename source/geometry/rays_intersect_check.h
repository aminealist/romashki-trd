bool point_on_ray(pt p, pt a, pt b) {
    pt ab(a, b);
    pt ap(a, p);
    ll s1 = ab ^ ap;
    ll s2 = ab * ap;
    return s1 == 0 && s2 >= 0;
}

bool rays_intersect(pt a, pt b, pt c, pt d) {
    pt ac(a, c);
    pt ab(a, b);
    pt cd(c, d);
    ll D = sign(-(ab ^ cd));
    ll D1 = sign(-(ac ^ cd));
    ll D2 = sign((ab ^ ac));
    if (D == 0) {
        return point_on_ray(a, c, d) || point_on_ray(c, a, b);
    }
    return D * D1 >= 0 && D * D2 >= 0;
}