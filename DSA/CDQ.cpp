int CDQ (int l, int r) {
    if (l == r) return;
    int mid = (l + r)/2;
    CDQ(l, mid), CDQ(mid+1, r);
    vector<int> tmp;
    for (int i = l, j = mid+1; i <= mid or j <= r; ) {
        while (i < mid and (j == r or y[ord[i]] <= y[ord[j]])) {
            bit.add(z[ord[i]], 1);
            tmp.push_back(ord[i]);
            i++;
        }
        if (j <= r) {
            ans[ord[j]] += bit.que(z[ord[j]]);
            tmp.push_back(ord[j]);
            j++;
        }
    }

    for (int i = l; i <= mid; i++) bit.add(z[ord[i]], -1);
    copy(tmp.begin(), tmp.end(), ord.begin() + l);
};