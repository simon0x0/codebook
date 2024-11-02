// 有限背包二進制拆分
int index = 0;
for(int i = 1; i <= m; i++){
    int c = 1, p, h, k;
    cin >> p >> h >> k;
    while(k > c){
        k -= c;
        list[++index].w = c * p;
        list[index].v = c * h;
        c *= 2;
    }
    list[++index].w = p * k;
    list[index].v = h * k;
}
// 之後再去做0/1背包