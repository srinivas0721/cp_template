#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1

//cses tree matching good question
int n;
vector<vector<int>> dp;
vector<vector<int>> adj;

void dp_on_tree(int node, int parent) {
    int sum = 0;
    for (auto it : adj[node]) {
        if (it == parent) continue;
        dp_on_tree(it, node);
        sum += max(dp[it][0], dp[it][1]);
    }

    // not taking (node unmatched with children)
    dp[node][0] = sum;

    // taking (node matched with exactly one child)
    dp[node][1] = 0;
    for (auto it : adj[node]) {
        if (it == parent) continue;
        int cand = 1 + dp[it][0] + (sum - max(dp[it][0], dp[it][1]));
        dp[node][1] = max(dp[node][1], cand);
    }
}
//tree diameter cses
vector<int>maxi1,maxi2;
void dp_on_tree(int node, int parent) { 
    int sum = 0;
    for (auto it : adj[node]) {
        if (it == parent) continue;
        dp_on_tree(it, node);
        int h = 1 + maxi1[it];
        int u = node;
        if(h>maxi1[u]){
            maxi2[u]=maxi1[u];
            maxi1[u]=h;
        }
        else{
            maxi2[u]=max(maxi2[u],h);
        }
    }
    ans = max(ans, maxi1[node] + maxi2[node]);
}



//Rerooting DP: Tree Distances I (cses)

const int N = 200005;
vector<int> in(N), out(N);
vector<vector<int>> adj;

void dfs1(int node, int parent) {
    in[node] = 0;
    for (auto it : adj[node]) {
        if (it == parent) continue;
        dfs1(it, node);
        in[node] = max(in[node], in[it] + 1);
    }
}

void dfs2(int node, int parent) {
    int mx1 = -1, mx2 = -1;
    int child = -1;

    // find best and second best child
    for (auto it : adj[node]) {
        if (it == parent) continue;
        int val = in[it] + 1;
        if (val > mx1) {
            mx2 = mx1;
            mx1 = val;
            child = it;
        } else if (val > mx2) {
            mx2 = val;
        }
    }

    for (auto it : adj[node]) {
        if (it == parent) continue;

        if (it == child) {
            // best child, so we must use second best for rerooting
            out[it] = max(out[node] + 1, mx2 == -1 ? 0 : mx2 + 1);
        } else {
            // not best child, safe to use mx1
            out[it] = max(out[node] + 1, mx1 == -1 ? 0 : mx1 + 1);
        }

        dfs2(it, node);
    }
}

//https://cses.fi/problemset/task/1133   (Tree Distances II)
vector<vector<int>> adj;
vector<int> subSize, dp;

void dfs1(int u, int p) {
    subSize[u] = 1;
    for (int v : adj[u]) if (v != p) {
        dfs1(v, u);
        subSize[u] += subSize[v];
        dp[u] += dp[v] + subSize[v];
    }
}

void dfs2(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        dp[v] = dp[u] - subSize[v] + (n - subSize[v]);
        dfs2(v, u);
    }
}

signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    adj.assign(n+1, {});
    dp.assign(n+1, vector<int>(2, 0));
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp_on_tree(1,-1);
    cout<<max(dp[1][0],dp[1][1])<<endl;

    return 0;
}