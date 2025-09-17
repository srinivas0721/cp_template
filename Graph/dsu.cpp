#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
class dsu {
    vector<int> parent, size, rank;
public:
    dsu(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        rank.assign(n+1, 0);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findpar(int node) {
        if(parent[node]==node) return node;
        return parent[node] = findpar(parent[node]);
    }
    void Unionsize(int u,int v){
        int pu = findpar(u), pv = findpar(v);
        if(pu==pv) return;
        if(size[pu] < size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        } else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    void UnionRank(int u,int v){
        int pu = findpar(u), pv = findpar(v);
        if(pu==pv) return;
        if(rank[pu]==rank[pv]){
            parent[pu]=pv;
            rank[pv]++;
        } else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        } else {
            parent[pv]=pu;
        }
    }
};
// https://codeforces.com/problemset/problem/25/D
// check this submission
signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    dsu d(n);


    //MsT : Minimum spamming tree
    int sum =0;
    for(auto it:edges){
        int w=it.first;
        int u=it.second.first;
        int v = it.second.second;
        if(d.findpar(u)!=d.findpar(v)){
            sum += w;
            d.UnionRank(u,v);
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
    cout<<sum<<endl;
    return 0;
}