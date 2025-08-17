#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;

//1328E CF

vector<vector<int>> dp_bin;
void dfs(int node, vector<vector<int>> &adj, int parent, vector<int> &level, int l = 0) {
    parent_map[node] = parent;
    dp_bin[node][0] = parent; // base case for binary lifting

    // Precompute 2^i-th ancestors and sums
    for (int i = 1; i < LOG; i++) {
        if (dp_bin[node][i - 1] != -1) {
            dp_bin[node][i] = dp_bin[dp_bin[node][i - 1]][i - 1];
        } else {
            dp_bin[node][i] = -1;
        }
    }

    level[node] = l;

    for (auto child : adj[node]) {
        if (child == parent) continue;
        dfs(child, adj, node, level, l + 1);
    }
}
int kth_parent_binary(int node, int k) {
    for (int i = 0; i < LOG; i++) {
        if ((k >> i) & 1LL) {
            node = dp_bin[node][i];
            if (node == -1) break;
        }
    }
    return node;
}
int lca(int a, int b, vector<int> &level) {
    if (level[a] < level[b]) swap(a, b);

    // 1. Lift 'a' up by the exact difference in depth
    a = kth_parent_binary(a, level[a] - level[b]);

    if (a == b) return a;

    // 2. Lift both until their parents are the same
    for (int i = LOG - 1; i >= 0; i--) {
        if (dp_bin[a][i] != dp_bin[b][i]) {
            a = dp_bin[a][i];
            b = dp_bin[b][i];
        }
    }

    // 3. Return parent
    return dp_bin[a][0];
}
signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>level(n+1,0);
    dfs(1, adj, -1, level);
    while(q--){
        int k;
        cin>>k;
        vector<int>v1(k,0);
        int lowezt_node =1,mini=LLONG_MAX,val=LLONG_MAX
        for(int i=0;i<k;i++){
            cin>>v1[i];
            mini= min(mini,level[v1[i]]);
            if(val>=mini){
                lowezt_node = v1[i];
                val=mini;
            }
        }
        bool flag = false;
        for(auto i:v1){
            if(lca(lowezt_node,i,level)!=i){
                if(level[i]-level[lca(lowezt_node,i,level)]!=1){
                    cout<<"NO"<<endl;
                    flag =true;
                    break;
                }
            }
        }
        if(!flag)
        cout<<"Yes"<<endl;
        
    }
    return 0;
}