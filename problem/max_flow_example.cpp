//有N個英雄、M隻怪物、K瓶藥水，一個英雄只能殺一個特定怪物
//喝藥水的英雄可以多殺一個怪物，一人最多喝一瓶，求最多殺幾隻怪物
//3 個英雄 5隻怪物 2瓶藥水
//第一個人可以殺掉第 1, 2, 3, 5 隻怪物
//第二個人可以殺掉第 2, 5 隻怪物
//第三個人可以殺掉第 1, 2 隻怪物 ，最終答案是 4
signed main(){
    int n, m, k; //英雄數量、怪物數量、藥水數量
    cin >> n >> m >> k;
    //設英雄節點為 0 ~ n-1
    //設怪物節點為 n ~ n+m-1
    int source = n + m + 1; //設定源點編號
    int sink = n + m + 2;   //設定匯點編號
    int potion = n + m;     //設定藥水編號
    flow.init(n+m+2+1, source, sink); //初始化點的數量,源點,匯點的index
    for(int heroIndex = 0, ni; heroIndex < n; heroIndex++){
        cin >> ni;
        for(int j = 0, monster; j < ni; j++){
            cin >> monster;
            flow.add_edge(heroIndex, n+monster-1, 1); //英雄可殺的怪物連邊
        }
        flow.add_edge(source, heroIndex, 1); //每個英雄最多可殺1隻怪物
        flow.add_edge(potion, heroIndex, 1); //每個英雄最多可喝1瓶藥水
    }
    for(int monsterIndex = 0; monsterIndex < m; monsterIndex++){
        flow.add_edge(n+monsterIndex, sink, 1); //每個怪物被殺1次
    }
    flow.add_edge(source, potion, k); // 源點到藥水k瓶
    cout << flow.flow(); //求答案
    return 0;
}