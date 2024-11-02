for(int i = 1; i <= cnt; i++)
    for(int j = w[i]; j <= weight; j++)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);