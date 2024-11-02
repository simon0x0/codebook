vector<pair<int,int>>vec[N];
void dijkstra(int s,int t){//起點，終點
    int dis[N];
    for(int i=0;i<N;i++){//初始化
        dis[i]=INF;//值要設為比可能的最短路徑權重還要大的值
    }
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;//以小到大排序
    pq.push({dis[s],s});
    while(pq.empty()==0){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto [v,w]:vec[u]){
            if(dis[u]+w<dis[v]){//鬆弛
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}