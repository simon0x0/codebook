bool vis[MXN];
void dfs(int x){
    vis[x] = 1;
    for(int i : flow.G[x]){
        if(i.f > 0 && !vis[i.v]){
            dfs(i.v);
        }
    }
}
dfs(source);