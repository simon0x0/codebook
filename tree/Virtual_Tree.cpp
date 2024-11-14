vector<int>virTree(vector<int> ver) {
    sort(ver.begin(),ver.end(),cmp); //用dfn排序
    vector<int>res(ver.begin(),ver.end());
    for(int i=1;i<ver.size();i++){
         res.push_back(lca(ver[i-1],ver[i]));//把LCA丟進虛樹內   
    }
    sort(res.begin(),res.end(),cmp);//在用dfn排序
    res.erase(unique(res.begin(),res.end()), res.end());//可能會有重複的點，需要去掉重複的
    return res;
}
int count_answer(vector<int>virTree){
    sort(virTree.begin(),virTree.end(),cmp);
    int ans=0;
    for(int i=1;i<virTree.size();i++){
        ans+=query(lca(virTree[i-1],virTree[i]),virTree[i]);
    }
    return ans;
}
/* 虛樹的題目都是大同小異，就只差在每個路徑需要詢問的事情是甚麼。
如果你看到題目有很多筆詢問，每筆詢問要選一些點做樹上問題，關鍵點數量總和不超過某個上限，那大概率就會是虛樹的題目 */