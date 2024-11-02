struct Matrix{
    int n, m;
    int v[105][105];
    Matrix(int _n, int _m): n(_n), m(_m){}
    void init(){ memset(v, 0, sizeof(v));}
    Matrix operator*(const Matrix B) const{
        Matrix C(n, B.m);
        C.init();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < B.m; j++){
                for(int k = 0; k < n; k++){
                    C.v[i][j] = C.v[i][j]+v[i][k]*B.v[k][j];
                }
            }
        }
        return C;
    }
    Matrix fastpow(Matrix &A, int y){
        Matrix C(A.n, A.m);
        C.init();
        for(int i = 0; i < C.n; i++) C.v[i][i] = 1;
        while(y){
            if(y & 1) C=C*A;
            A = A*A;
            y >>= 1;
        }
        return C;
    }
};