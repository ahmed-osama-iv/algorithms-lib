typedef long long ll;

vector<vector<ll> > matrixMult(vector<vector<ll> > &A, vector<vector<ll> > &B, const int N, const int R, const int M ){ //where A is NxR & B is RxM
    vector<vector<ll> > C (N);

    for(int i = 0; i < N; ++i)
        C[i].resize(M,0);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            for(int k = 0; k < R; ++k)
                C[i][j]+=A[i][k]*B[k][j];
    return C;
}

vector<vector<ll> > matrixPow(vector<vector<ll> > &A, const int N, int pow ){ //where A is NxN
    vector<vector<ll> > I (N);

    for(int i = 0; i < N; ++i){
        I[i].resize(N,0);
        I[i][i] = 1;
    }

    vector<vector<ll> > base=A, ans=I;

    while(pow){
        if(pow&1){
            ans=matrixMult(ans,base,N,N,N);
            pow--;
        }
        else{
            base=matrixMult(base,base,N,N,N);
            pow/=2;
        }
    }
    return ans;
}
