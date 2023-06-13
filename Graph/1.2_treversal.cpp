#include<bits/stdc++.h>
using namespace std;

vector<int> BFSofGraph(int V , vector<int> adj[]){

    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> ans ;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans ;
// s.c. = o(n) and the t.c. = o(n) + o(2*E)
}

void dfs(int node , int vis[] , vector<int> adj[] , vector<int> &ans){
    vis[node] = 1;
    ans.push_back(node);
    for(auto it: adj[node]){
        if(vis[it] == 0){
            dfs(it , vis , adj , ans);
            }
    }
}

vector<int> DFSofGraph(int V , vector<int> adj[]){
    int vis[V] =  {0};
    int start  = 0;
    vector<int> ans ;
    dfs(start , vis , adj , ans);
    return ans ;
// sc is o(n) and the tc is o(n) + o(2*E) 
}


int main(){


    return 0;
}