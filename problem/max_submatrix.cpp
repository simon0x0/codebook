for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) { //初始化
      l[j] = r[j] = j;
    }
    char c;
    for (int j = 1; j <= m; j++) { //對每一個直行做統計，若是上一個a[j]也是1則會變成2
      cin>>c;
      if (c == 'F') a[j]++;
      else if (c == 'R') a[j] = 0;
    }
    for (int j = 1; j <= m; j++)
      while (l[j] != 1 && a[l[j] - 1] >= a[j]) l[j] = l[l[j] - 1];
    for (int j = m; j >= 1; j--)
      while (r[j] != m && a[r[j] + 1] >= a[j]) r[j] = r[r[j] + 1];
    for (int j = 1; j <= m; j++) ans = max(ans, (r[j] - l[j] + 1) * a[j]);
  }