 #include<bits/stdc++.h>
 using namespace std;
 
int spanningTree(int V, vector<vector<int>> adj[]){
        // code here
        priority_queue<pair<int,int> ,
        vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        vector<int> vis(V,0);
        int ans = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            if(vis[node]) continue;
            vis[node] = 1;
            
            ans += wt;
            
            for(auto it: adj[node]){
                int adjn = it[0];
                int edw = it[1];
                
                if(!vis[adjn]){
                    pq.push({edw,adjn});
                }
            }
        }
        return ans;
}

int main(){
    return 0;
}