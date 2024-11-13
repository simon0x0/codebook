int n,k = sqrt(n);//每塊大小為k
struct query{
    int l,r,id;
    bool operator<(const query &lhs, const query &rhs){
        if(lhs.l/k!=rhs.l/k)	return lhs.l/k<rhs.l/k;
        return ((lhs.l/k)&1?lhs.r<rhs.r:lhs.r>rhs.r);
}
};
int num = 0;
int cnt[1'000'005], ans[30'005];
vector<query> q;
void add(int index){ ... }
void sub(int index){ ... }
void solve(){
    sort(q.begin(),q.end());
    for(int i=0,l=0,r=-1;i<n;i++){
        while(l>q[i].l) add(--l);
        while(r<q[i].r) add(++r);
        while(l<q[i].l) sub(l++);
        while(r>q[i].r) sub(r--);
        ans[q[i].id] = num;
}    }