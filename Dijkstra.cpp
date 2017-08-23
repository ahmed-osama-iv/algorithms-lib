    const int MAXN = 100005;
    const long long INF = 1e16; //greater than (max node wight) * number of nodes;
    long long dist[MAXN];
    int parent[MAXN];
     
    vector<pair<int,long long> > adj[MAXN];
     
    struct cmp{
        bool operator () (pair<int,long long> a,pair<int,long long> b){
            return (a.second>b.second);
        }
    };
     
    //find the shortest path from the source to every node reachable from it 
    void dijkstra(int src){
     
        for(int i=0;i<MAXN;i++)
            dist[i]=INF;
     
        priority_queue< pair<int, long long>, vector< pair<int, long long> >, cmp> q;
        q.push({src,dist[src]=0});
        parent[src]=-1;
     
        while(!q.empty()){
            int node = q.top().first;
            long long cost = q.top().second;
            q.pop();
     
            if(dist[node]==cost){
                for(auto it : adj[node]){
                    int tnode = it.first;
                    long long edgeCost = it.second;
                    if(cost+edgeCost<dist[tnode]){
                        parent[tnode] = node;
                        q.push({tnode,dist[tnode]=cost+edgeCost});
                    }
                }
            }
        }
    }
     
    //get the path from node n to the source;
    vector<int> getPath(int n){
        vector<int> path;
        while(n!=-1){
            path.push_back(n);
            n=parent[n];
        }
        reverse(path.begin(),path.end());
        return path;
    }
