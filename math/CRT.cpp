LL exgcd(LL a,LL b,LL &x,LL &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int now=exgcd(b, a % b, y, x);
    y -= a / b * x;
    return now;
}
LL CRT(LL k, LL* a, LL* r) {
    LL n = 1, ans = 0;
    for (LL i = 1; i <= k; i++) {
        n = n * r[i];
    }
    for (LL i = 1; i <= k; i++) {
        LL m = n / r[i], b, y;
        exgcd(m, r[i], b, y);
        ans = (ans + a[i] * m * b % n) % n;
    }
    return (ans % n + n) % n;
}