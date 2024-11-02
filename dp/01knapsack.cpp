for (int i = 1; i <= cnt; i++) //幾個物品
  for (int j = weight; j >= w[i]; j--) //從物品耐重上限枚舉到此物品的重量，代表每個都最多選一次
    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);