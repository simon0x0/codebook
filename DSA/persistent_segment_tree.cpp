struct node{
    ll val;
    node *l, *r;
};
vector<node *> ver;    //用一個vector紀錄全部版本的根節點
void build(node *now_ver, l, r);
ll query(node *now_ver, l, r, ql, qr);
node *update_ver(node *pre_ver,int l,int r,int pos,int v); //回傳新建的節點
void add_ver(int x,int v){    //修改位置 x 的值為 v
    ver.push_back(update_ver(ver.back(), 0, n-1, x, v));
}
node *update_ver(node *pre_ver, node *x, int l, int r, int pos, int v){
    node *x = new node();    //當前位置建立新節點
    if(l == r){
        x->val = v;
        return x;
    }
    int mid = (l+r)>>1;
    if(pos <= mid){ //更新左邊
        x->l = update(pre_ver->l, x->l, l, mid, pos, v); //左邊節點連向新節點
        x->r = pre_ver->r;                        //右邊連到原本的右邊
    }
    else{ //更新右邊
        x->l = pre_ver->l;                         //左邊連到原本的左邊
        x->r = update(pre_ver->r, x->r, mid+1, r, pos, v);  //右邊節點連向新節點
    }
    x->val = x->l->val + x->r->val;
    return x;
}