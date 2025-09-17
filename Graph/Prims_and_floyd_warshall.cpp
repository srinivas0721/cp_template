#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX/4   // avoid overflow
const int MOD = 1e9 +7;

signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);

    // adjacency list for Prim's
    // adjacency matrix for Floyd-Warshall
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));

    for(int i=1;i<=n;i++) dist[i][i] = 0;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        dist[u][v] = min(dist[u][v], w); // in case of multi-edge
        dist[v][u] = min(dist[v][u], w);
    }

    // ----------------- Prim's MST -----------------
    priority_queue<vector<int>> pq;
    vector<int> vis(n+1,0);
    pq.push({0,1,0}); // { -wt, node, parent }

    int sum = 0;
    vector<pair<int,int>> edges;

    while(!pq.empty()){
        int node = pq.top()[1];
        int wt   = -pq.top()[0];
        int par  = pq.top()[2];
        pq.pop();

        if(vis[node]) continue;
        vis[node]=1;
        sum += wt;

        if(par!=0) edges.push_back({node,par});

        for(auto it:adj[node]){
            if(!vis[it.first]){
                pq.push({-it.second,it.first,node});
            }
        }
    }

    cout<<"MST weight = "<<sum<<endl;
    cout<<"MST edges:"<<endl;
    for(auto it:edges){
        cout<<it.first<<" "<<it.second<<endl;
    }

    // ----------------- Floyd–Warshall -----------------
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]<INF && dist[k][j]<INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Detect negative cycles
    bool neg_cycle = false;
    for(int i=1;i<=n;i++){
        if(dist[i][i] < 0) neg_cycle = true;
    }

    if(neg_cycle) cout<<"Graph contains a negative weight cycle!"<<endl;

    // Example usage:
    int a,b,via;
    cout<<"Enter a, b, via (for shortest path a->via->b): ";
    cin>>a>>b>>via;

    if(dist[a][via]==INF || dist[via][b]==INF) {
        cout<<"No path exists from "<<a<<" -> "<<b<<" via "<<via<<endl;
    } else {
        cout<<"Shortest path "<<a<<" -> "<<b<<" via "<<via<<" = "
            << dist[a][via] + dist[via][b] <<endl;
    }

    return 0;
}
