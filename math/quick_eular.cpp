int prime[10010], phi[10010];
bool v[10010];
void quick_euler(){
	int cnt = 0;
	for(int i = 2; i <= N; ++i){
		if(!v[i])	prime[++cnt] = i, phi[i] = i - 1;
        // 若 i 是質數，所以 φ(i) = i - 1
		for(int j = 1; i * prime[j] <= N && j <= cnt; ++j){
			v[i * prime[j]] = 1;
			if(i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
			 	break;
			 }
			 else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}