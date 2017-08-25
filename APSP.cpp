#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct APSP{

    static const int MAXN = 205; //larger than number of nodes
    static const int inf = 1e9; //larger than any possible path between any two nodes
    //be careful that 2*inf must fit in the data type

    int dist[MAXN][MAXN]; //distance array
    int path[MAXN][MAXN]; //path array

    void getPath(int src, int dest) { //source , destination
        if(path[src][dest] == -1) {
            cout << src << " "; // beytalla3 kolo ma 3ada a5er node
            return;
        }
        getPath(src, path[src][dest]);
        getPath(path[src][dest], dest);
    }

    void initialize(){
        memset(path,-1, sizeof path);
            for(int i = 0; i < MAXN; i++)
                for(int j = 0; j < MAXN; j++)
                    dist[i][j] = inf;
    }

    void floyd(int n){ //O(n^3)
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        path[i][j] = k;
                    }
    }

};

int main(){
        APSP ap;
        ap.initialize(); //initialize dist and path arrays;
        //read the graph dist[i][j] for all available i and j;
        ap.floyd(n+1); //run Floyd Warshal on the graph in dist
}
