#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int MOD = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,long long>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v,w;
        cin >> u >> v>>w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n+1, INF);
    vector<int> ways(n+1, 0);
    vector<int> minFlights(n+1, INT_MAX);
    vector<int> maxFlights(n+1, INT_MIN);
    using P = pair<long long,int>; // {distance, node}
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[1] = 0;
    ways[1] = 1;
    minFlights[1] = 0;
    maxFlights[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        if (d > dist[u]) continue; // s
        for(auto [v,w]:adj[u]){
            if(dist[v]>d+w){
                dist[v]=d+w;
                ways[v]=ways[u];
                minFlights[v]=minFlights[u]+1;
                maxFlights[v]=maxFlights[u]+1;
                pq.push({dist[v], v});
            }
            else if(dist[v]==d+w){
                ways[v]=(ways[v]+ways[u])%(MOD);
                maxFlights[v]=max(maxFlights[u]+1,maxFlights[v]);
                minFlights[v]=min(minFlights[u]+1,minFlights[v]);
            }
        }
    }
    cout << dist[n] << " "<< ways[n] % MOD <<" "<< minFlights[n] << " " << maxFlights[n] << "\n";
}
