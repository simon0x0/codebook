dp[3][26]=dp[3][11010] //現在的點為3，走過1,3,4這三個點
if( edge[i][j] && ( (1<<j) & s ) == 0 ){
    //i->j有邊且點j尚未走過
    dp[j][s|(1<<j)]=dp[i][s];
}
//以下為程式碼
for(int s=0;s<(1<<n);s++){//枚舉點集合
    for(int i=0;i<n;i++){//枚舉現在的點
        if(s&(1<<i)==0)continue;
        for(int j=0;j<n;j++){//枚舉下一個點
            if(i==j)continue;
            if( edge[i][j] && ( (1<<j) & s ) == 0 ){
                dp[j][s|(1<<j)]=dp[i][s];
            }
        }
    }
}