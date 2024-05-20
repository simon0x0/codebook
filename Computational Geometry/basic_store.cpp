struct Pt{
    double x, y;
};
struct Line{
    double st, ed;
};
struct Circle{
    Pt o; // 圓心
    double r; // 半徑
};
struct poly{
    int n; // n邊形
    vector<Pt> pts;
};