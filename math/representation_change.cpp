int ntod(string str, int n){ // n進制轉10進制
    int ans = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= '0' && str[i]<='9')
            ans = ans * n + str[i] - '0';
        else// 小寫減a 大寫減A
            ans = ans * n + str[i] - 'a' + 10;
    }
    return ans;
}
string dton(int num , int n){ // 10進制轉n進制
    string ans = "";
    do{
        int t = num % n;
        if(t >= 0 && t <= 9)
            ans += t + '0';
        else
            ans += t - 10 + 'a';
        num /= n;
    } while(num != 0);
    reverse(ans.begin(), ans.end());
    return ans;
}