bool collinearity(Pt p1, Pt p2, Pt p3){ // 三點共線
    return cross(p2 - p1, p3 - p1) == 0;
}
bool inLine(Pt st, Pt ed, Pt p){ // 點是否在線上
    return collinearity(st, ed, p) && dot(p, st, ed) < 0;
}