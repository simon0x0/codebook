bool dfs(int u){
    for(int i=1;i<=n;i++){
        if(Map[u][i]&&!vis[i]){ //有連通且未拜訪
            vis[i]=1; //紀錄是否走過
            if(S[i]==-1||dfs(S[i])){  //紀錄匹配
                S[i]=u;
                return true;  //反轉匹配邊以及未匹配邊的狀態
            }
        }
    }
    return false;
}
// 記得每次使用需清空vis數組
// 其中Map為鄰接表 S為紀錄這個點與誰匹配
for(int i=1;i<=p;i++){
    memset(vis,0,sizeof(vis));
    if(dfs(i)) ans++;
}