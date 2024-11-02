long long fac[MXN], inv[MXN];
fac[0] = 1; // 0! = 1
for(long long i = 1; i <= N; i++)    
    fac[i] = fac[i-1] * i % MOD;
inv[N] = FastPow(fac[N], MOD-2); // 快速冪
for(long long i = N-1; i >=0; i--)
    inv[i] = inv[i+1] * (i+1) % MOD;
