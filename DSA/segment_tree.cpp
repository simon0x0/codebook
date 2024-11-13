// 區間修改 查詢區間和
#define cl(x) (x<<1)
#define cr(x) (x<<1)+1
int seg[4*N], lazy[4*N], arr[N];
void build(int id, int l, int r){
    if(l == r){
        seg[id] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(cl(id), l, mid);
    build(cr(id), mid+1, r);
    seg[id] = seg[cl(id)] + seg[cr(id)];
}
void propagation(int id, int l, int r){
    if(lazy[id]){
        seg[id] += (r - l + 1) * lazy[id];
        if(l != r){
            lazy[cl(id)] += lazy[id];
            lazy[cr(id)] += lazy[id];
        }
        lazy[id] = 0;
    }
}
int query(int id, int l, int r, int ql, int qr){
    propagation(id, l, r);
    if (ql > r || qr < l) return 0;
    if(ql <= l && qr >= r) return seg[id];
    int mid = (l + r) >> 1;
    return query(cl(id), l, mid, ql, qr) + query(cr(id), mid+1, r, ql, qr);
}
void update(int id, int l, int r, int sl, int sr, int v){
    propagation(id, l, r);
    if(sl > r || sr < l) return;
    if(sl <= l && r <= sr){
        lazy[id] += v;
        propagation(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(cl(id), l, mid, sl, sr, v);
    update(cr(id), mid+1, r, sl, sr, v);
    seg[id] = seg[cl(id)] + seg[cr(id)];
}