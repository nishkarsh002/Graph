#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int>  dist(V , INT_MAX);
    dist[S] = 0;
    q.push({S,0});
         
    while(!q.empty()){
        int dis = q.top().second;
        int node = q.top().first;
        q.pop();
             
        for(auto it : adj[node]){
            int  v = it[0];
            int wt = it[1];
            if(dis + wt < dist[v]){
                dist[v] = dis + wt;
                q.push({v , dist[v]});
            }
        }
    }
    return dist;
}

vector <int> shortestPath(int V, vector<vector<int>> adj[] ,int src)   // using set
{
    set< pair<int, int> > setds;
 

    vector<int> dist(V, 1e9);
 
    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;
 
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        auto it = *(setds.begin());
        setds.erase(it);
 
        
        int node = it.second;
        int dis = it.first;

 
        // 'i' is used to get all adjacent vertices of a vertex
        for(auto it: adj[node])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = it[0];
            int weight = it[1];
 
            //    If there is shorter path to v through u.
            if (dist[v] > dis + weight)
            {
                
                if (dist[v] != 1e9)
                    setds.erase({dist[v],v});
 
                // Updating distance of v
                dist[v] = dis + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist;

}

int main(){
    return 0;
}

// (E*logv)