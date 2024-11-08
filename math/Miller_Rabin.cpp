// n < 4,759,123,141        3 :  2, 7, 61
// n < 2^64                       7 :
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022
// 或前12個質數
#define LL __int128
LL magic[]={}
bool witness(LL a,LL n,LL u,int t){
	if(!a) return 0;
	LL x=mypow(a,u,n);
	for(int i=0;i<t;i++) {
		LL nx=mul(x,x,n);
		if(nx==1&&x!=1&&x!=n-1) return 1;
		x=nx;
	}
	return x!=1;
}
bool miller_rabin(LL n) {
	int s=(magic number size)
	// iterate s times of witness on n
	if(n<2) return 0;
	if(!(n&1)) return n == 2;
	ll u=n-1; int t=0;
	// n-1 = u*2^t
	while(!(u&1)) u>>=1, t++;
	while(s--){
		LL a=magic[s]%n;
		if(witness(a,n,u,t)) return 0;
	}
	return 1;
}