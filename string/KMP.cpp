vector<int> KMP(string s, string t){
    s = t + '@' + s;
    int sz = s.size();
    vector<int> pi(sz);
    for(int i = 1; i < sz; i++){
        int len = pi[i-1];
        while(len != 0 && s[i] != s[len]) len = pi[len-1];
        if(s[i] == s[len]) pi[i] = len+1;
    }
    return pi;
}