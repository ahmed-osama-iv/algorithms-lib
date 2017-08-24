#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct sparseTable{

    static const int MAXN=100005; //max arr size
    static const int K = log(MAXN) / log(2); // max lv

    int Arr[MAXN]; //input array
    int SpT[MAXN][K+1]; //sparse table array

    void build(int n){

        for(int i = 0; i < n; i++)
            SpT[i][0] = i;

        for(int j = 1; (1<<j) <= n; j++)
            for(int i = 0; i + (1 << j) - 1 < n ; i++)
                if (Arr[SpT[i][j-1]] < Arr[SpT[i+(1<<(j-1))][j-1]])
					SpT[i][j] = SpT[i][j-1];
				else
                    SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
    }
    
    //idempotent functions 
    int query(int i, int j){ // O(log n)

	    int k = log(j-i+1) /log(2); 

	    if (Arr[SpT[i][k]] <= Arr[SpT[j-(1<<k)+1][k]])
	    	return SpT[i][k]; 
	    else
	    	return SpT[j-(1<<k)+1][k];
        //returns the index of minimum
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
        printf("%d\n",sp.Arr[sp.query(l,r)]);
    }
}
