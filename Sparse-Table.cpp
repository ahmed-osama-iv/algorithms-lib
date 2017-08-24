struct sparseTable{

    static const int MAXN=100005; //max arr size
    static const int K = log(MAXN) / log(2); // max lv
    static const int I=INT_MAX;

    int Arr[MAXN]; //input array
    int SpT[MAXN][K+1]; //sparse table array

    int op(int a,int b){
        return min(a,b);
    }
    void build(int n){

        for(int i = 0; i < n; i++)
            SpT[i][0] = Arr[i];

        for(int j = 1; (1<<j) <= n; j++)
            for(int i = 0; i + (1 << j) -1 < n ; i++)
                SpT[i][j]=op(SpT[i][j-1], SpT[i+(1<<(j-1))][j-1]);
    }
    //general case
    int query(int l, int r){ // O(log n)

        int res = I;
        for(int j = K; j >= 0; j--)
            if(l + (1 << j) - 1 <= r) {
                res = op(res, SpT[l][j]);
                l += 1 << j; // instead of having L', we increment L directly
            }
        return res;
    }
};
