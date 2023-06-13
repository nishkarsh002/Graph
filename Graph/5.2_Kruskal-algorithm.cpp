#include<bits/stdc++.h>
using namespace std;

class Solution{  // the dsu
    vector<int> rank, parent;
    int findParent(int node){
        if(node == parent[node])
            return node;
            
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[u]++ ;
        }
    }
    
public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        rank.resize(V) ;
        parent.resize(V) ;
        for(int i=0; i<V; i++)
            parent[i] = i;
        
        vector<vector<int>> edges;
        for(int u=0; u<V; u++){
            for(auto nbr : adj[u]){
                int v = nbr[0];
                int wt = nbr[1];
                edges.push_back({wt , u, v}) ;
            }
        }
        sort(edges.begin(), edges.end()) ;
        int MSTcost = 0;
        for(auto &e : edges){
            int u = e[1] , v = e[2], wt = e[0] ;
            //checking is both node are already reachable or not
            //or we can say both are in same component or not
            int pu = findParent(u) , pv = findParent(v);
            if(pu != pv){
                MSTcost += wt;
                unionByRank(u, v);
            }
        }
        return MSTcost;
    }
};

int main(){
    return 0;
}