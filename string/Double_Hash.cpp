const int mod = 1e9 + 7;
pair<int, int> Hash[N];
void get_hash(string s){
    int p1 = 13331, p2 = 75577;
    pair<int, int> val = {0, 0};
    for(int i = 0; i < s.size(); i++){
        val.first = (val.first * p1 + s[i]) % mod;
        val.second = (val.second * p2 + s[i]) % mod;
        Hash[i] = val;
    }
}