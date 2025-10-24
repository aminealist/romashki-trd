
struct pt {
    ll x = 0, y = 0;

    pt() = default;
    pt(ll xx, ll yy) : x(xx), y(yy) {}
    pt(pt s, pt e) : x(e.x - s.x), y(e.y - s.y) {}
    pt(const pt &s) : x(s.x), y(s.y) {}

    ld len() { return sqrtl(len2()); }
    ll len2() { return x * x + y * y; }
    ll manhat_len() { return abs(x) + abs(y); }
    ll operator*(pt p) { return x * p.x + y * p.y; }
    ll operator^(pt p) { return x * p.y - y * p.x; }
    pt operator+(pt p) { return pt(p.x + x, p.y + y); }
    pt operator-(pt p) { return pt(x - p.x, y - p.y); }
    bool operator==(pt p) { return x == p.x && y == p.y; }
    bool operator!=(pt p) { return !(*this == p); }
    friend istream &operator>>(istream &in, pt &p) { return in >> p.x >> p.y; }
    friend ostream &operator<<(ostream &out, pt &p) {
        return out << p.x << ' ' << p.y;
    }
};

ld angle(pt p1, pt p2) {
    return std::abs(atan2(p1 ^ p2, p1 * p2));
}