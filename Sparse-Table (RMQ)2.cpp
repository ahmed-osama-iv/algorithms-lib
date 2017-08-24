#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct sparseTable{

    static const int MAXN=100005; //max arr size
    static const int K = log(MAXN) / log(2); // max lv

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

    //idempotent functions
    int query(int l, int r){ // O(log n)
    
      int k = log(r-l+1) /log(2);
      return op(SpT[l][k],SpT[r-(1<<k)+1][k]);
    }
};

int main(){
    sparseTable sp;
    int n,q,l,r;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d",&sp.Arr[i]);
    }
    sp.build(n);
    scanf("%d",&q);
    for(int i =0;i<q;i++){
        scanf("%d %d",&l,&r);
        printf("%d\n",sp.query(l,r));
    }
}
