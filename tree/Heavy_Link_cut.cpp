int par[MXN], dep[MXN], sz[MXN], son[MXN];
void dfs1(int now, int fa, int now_deep){//當前節點, 爸爸, 目前深度
    dep[now] = now_deep;
    par[now] = fa;
    sz[now]  = 1;
    for(auto nxt : v[now]){
        if(nxt == fa)continue;
        dfs1(nxt, now, now_deep + 1);
        sz[now] += sz[nxt];
        if(sz[nxt] > sz[son[now]]) son[now] = nxt;
    }
}
int top[MXN], dfn[MXN], rnk[MXN];
int cnt = 0;
void dfs2(int now, int fa, int now_top){//現在的點, 爸爸, 目前的頂端點
    top[now] = now_top;
    rnk[now] = cnt;
    dfn[now] = cnt++;
    if(son[now] != 0) dfs2(son[now], now, now_top);//為了讓編號連續，先往重兒子走
    for(auto nxt : v[now]){
        if(nxt == fa || nxt == son[now])continue;
        dfs2(nxt, now, nxt);//往其他輕兒子走
    }
}
int getlca(int x,int y){
    while(top[x] != top[y]){
        if( dep[top[x]] < dep[top[y]] )//根據頂端點的深度往上跳
            y = par[top[y]];
        else 
            x = par[top[x]]; 
    }
    if(dep[x] > dep[y])return y;//這時候在同一條鏈了，回傳比較不深的點
    else return x;
}
int query(int x, int y){ //求路徑點權總和O((logn)^2)
    int lca = getlca(x, y);
    int ans = 0;
    //x -> lca 點權總和
    while( top[lca] != top[x] ){
        ans += seg.query( dfn[top[x]], dfn[x] );
        x = par[top[x]];
    }
    ans += seg.query( dfn[lca], dfn[x] );
    //y -> lca 點權總和
    while( top[lca] != top[y] ){
        ans += seg.query( dfn[top[y]], dfn[y] );
        y = par[top[y]];
    }
    ans += seg.query( dfn[lca], dfn[y] );
    ans -= seg.query( dfn[lca], dfn[lca] );//lca被重複算到一次，要扣掉
}