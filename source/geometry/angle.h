ld angle(pt p1, pt p2) {
    return std::abs(atan2(p1 ^ p2, p1 * p2));
}

ll sign(ll x) {
    return (x > 0) - (x < 0);
}

bool polar_angle_cmp(pt a, pt b) {
    if (a.hp_pos() != b.hp_pos())
        return a.hp_pos() > b.hp_pos();
    ll s = sign(a ^ b);
    if (s != 0)
        return s > 0;
    return a.manhat_len() < b.manhat_len();
}