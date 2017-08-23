int N;
const int MAXNODE = 1000006;
 
struct edge{
    int from, to;
    long long cost;
};
 
edge edgeList[MAXNODE];
 
struct DSU{
 
    int id[MAXNODE], sz[MAXNODE];
 
    DSU(){
        for(int i =0;i<MAXNODE;i++)
            id[i]=i,sz[i]=1;
    }
 
    int root(int i){
        while(i != id[i])
            i = id[i] = i[id][id];
        return i;
 
    }
 
    bool unite(int a , int b){
        a=root(a),b=root(b);
        if(a==b) return 0;
        if (sz[a] < sz[b]) swap(a, b);
        if (sz[a] == sz[b]) ++sz[a];
        id[b] = a;
        return 1;
    }
};
 
bool comp (edge a, edge b){
    return a.cost<b.cost;
}
 
int kruskal(int m){
 
    int MAX_Cost=0;
    int pathN=0;
    DSU D;
    sort(edgeList,edgeList+m,comp);
    for(int i =0;i<m;i++)
        if(D.unite(edgeList[i].from,edgeList[i].to)){
            MAX_Cost=edgeList[i].cost;
            pathN++;
        }
 
    return (pathN!=N-1?-1: MAX_Cost);
}
 
