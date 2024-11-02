vector<int> tmp(arr);  //將arr複製到tmp
sort(tmp.begin(), tmp.end());
tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
for (int i = 0; i < n; i++)
  arr[i] = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();