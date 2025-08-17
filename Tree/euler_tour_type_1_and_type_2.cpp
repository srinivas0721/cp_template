#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 +7;

// ======================= Type-1: Euler Tour (for LCA) =======================
vector<int> flat;     // stores the Euler tour nodes
vector<int> lev;      // stores the levels (depths) in Euler tour
map<int,int> mp;      // stores first occurrence index of each node
int idx = 0;          // index of Euler tour

// DFS to build Euler Tour (Type-1)
void dfs(int node,int par,vector<vector<int>>& adj,int depth){
    if(mp.find(node)==mp.end()){   // first occurrence of node
        mp[node]=idx;
    }
    flat.push_back(node);   // push node into Euler tour
    lev.push_back(depth);   // store its depth
    idx++;

    for(auto it:adj[node]){
        if(it==par) continue;
        dfs(it,node,adj,depth+1);

        // push parent again when returning
        flat.push_back(node);
        lev.push_back(depth);
        idx++;
    }
}

// ======================= Type-2: Euler Tour (for Subtrees) =======================
int idx1 = 0;
map<int,pair<int,int>> mp1;   // mp1[node] = {entry, exit}
vector<int> flat2;            // Euler order (entry sequence only)

void dfs_type_2(int node,int par,vector<vector<int>>& adj){
    mp1[node].first = idx1;   // entry time
    flat2.push_back(node);
    idx1++;

    for(auto it:adj[node]){
        if(it==par) continue;
        dfs_type_2(it,node,adj);
    }

    mp1[node].second = idx1; 
    // exit time (last index of its subtree)
    flat2.push_back(node);
    idx1++;
}

// ======================= Sparse Table for LCA =======================
struct SparseTable {
    int n, LOG;
    vector<vector<int>> table;

    SparseTable(const vector<int> &a) {
        n = a.size();
        LOG = __lg(n) + 1;
        table.assign(n, vector<int>(LOG));
        for (int i = 0; i < n; i++)
            table[i][0] = i;  // store index, not value

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                int left = table[i][j - 1];
                int right = table[i + (1 << (j - 1))][j - 1];
                table[i][j] = (a[left] < a[right] ? left : right);
            }
        }
    }

    int query(const vector<int> &a,int l,int r) {
        int j = __lg(r - l + 1);
        int left = table[l][j];
        int right = table[r - (1 << j) + 1][j];
        return (a[left] < a[right] ? left : right);
    }
};

// Find LCA using Sparse Table on lev[]
int LCA(int a,int b,SparseTable &st){
    int l = mp[a];
    int r = mp[b];
    if(l > r) swap(l,r);
    int idx = st.query(lev,l,r);  // index of min depth in [l,r]
    return flat[idx];             // return corresponding node
}

// ======================= Main =======================
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // run DFS from root = 1 at depth = 0
    dfs(1,-1,adj,0);
    dfs_type_2(1,-1,adj,0);

    // Build Sparse Table on lev[] for LCA
    SparseTable st(lev);

    int q;
    cin>>q;
    while(q--){
        int type; cin>>type;
        if(type==1){
            // LCA query
            int u,v;
            cin>>u>>v;
            cout<<"LCA("<<u<<","<<v<<") = "<<LCA(u,v,st)<<endl;
        }
        else if(type==2){
            // Subtree query: print all nodes in subtree of u
            int u; cin>>u;
            cout<<"Subtree of "<<u<<": ";
            for(int i=mp1[u].first;i<=mp1[u].second;i++){
                cout<<flat2[i]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
