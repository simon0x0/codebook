void dfs(int u, int fa) {  // 預處裡dfs
  sz[u] = 1; // 以 u 為根的子樹數量
  dep[u] = dep[fa] + 1; // u 的深度
  for (int v : edge[u]) { //遍歷 u 的子節點
    if (v != fa) { //不等於父親
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}
void get_ans(int u, int fa) {  // 第二次dfs換根dp
  for (int v : edge[u]) { //遍歷子節點
    if (v != fa) {
      dp[v] = dp[u] - sz[v] * 2 + n; //轉移式
      get_ans(v, u);
    }
  }
}