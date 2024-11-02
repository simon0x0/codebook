// 如果發生碰撞可以做雙重雜湊
const ll P = 75577; // p = 13331, 14341, 75577
const ll MOD = 998244353; //MOD = 1e9+7, 998244353, 999997771
ll Hash[MXN];    //Hash[i] 為字串 [0,i] 的 hash值
void build(const string& s){
    int val = 0;
    for(int i=0; i<s.size(); i++){
        val = (val * P + s[i]) % MOD;
        Hash[i] = val;
    }
}
// h[l, r] = h[r] - h[l-1] * p^(r-l+1)