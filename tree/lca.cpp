int timing;
int in[N],out[N];
void dfs(int u){
    in[u] = ++timing;//這時進入u
    for(int nxt : g[u])//跑過所有孩子
        dfs(nxt);
    out[u] = ++timing;//這時離開u
}
bool is_ancestor(int u,int v){ //用=因為自己是自己的祖先
    return in[u] <= in[v] && out[u] >= out[v]; //u是v的祖先
}
int getlca(int x, int y){
    if(is_ancestor(x, y))return x; // 如果 u 為 v 的祖先則 lca 為 u
    if(is_ancestor(y, x))return y; // 如果 v 為 u 的祖先則 lca 為 u
    for(int i=logN;i>=0;i--){    // 判斷 2^logN, 2^(logN-1),...2^1, 2^0 倍祖先
        if(!is_ancestor(anc[x][i], y)) // 如果 2^i 倍祖先不是 v 的祖先
            x = anc[x][i];            // 則往上移動
    }
    return anc[x][0]; // 回傳此點的父節點即為答案
}
int anc[N][logN]; //倍增法，從x往上走i步
signed main(){
    for(int i=1;i<=log2(N);i++){
        for(int now=1;now<=N;now++){
            anc[now][i]=anc[anc[now][i-1]][i-1];
        }
    }   
}