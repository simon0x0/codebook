bool intersect(Pt a, Pt b, Pt c, Pt d){ // 線段相交
    return (cross(b - a, c - a) * cross(b - a, d - a) < 0 && cross(d - c, a - c) * cross(d - c, b - c) < 0)
            || inLine(a, b, c) || inLine(a, b, d) || inLine(c, d, a) || inLine(c, d, b);
}
Pt intersection(Pt a, Pt b, Pt c, Pt d){ // 線段交點
    assert(intersect(a, b, c, d)); // 沒有交點的狀況
    return a + cross(a - c, d - c) * (b - a) / cross(d - c, b - a);
}