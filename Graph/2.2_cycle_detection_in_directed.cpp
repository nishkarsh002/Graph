#include <bits/stdc++.h>
using namespace std;

bool check(int node, vector<int>adj[], vector<int>& vis, vector<int>& path){
        vis[node] = 1;
        path[node] = 1;
        for(int i=0; i<adj[node].size(); i++){
            if(vis[adj[node][i]] == 0){
                if(check(adj[node][i], adj, vis, path) == true){
                    return true;
                }
            }
            else if(vis[adj[node][i]] == 1 && path[adj[node][i]] == 1){
                return true;
            }
        }

        path[node] = 0;
        return false;
}

    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(check(i, adj, vis, path) == true){
                    return true;
                }
            }
        }
        return false;
    }

int main(){
    return 0;
}