#include <bits/stdc++.h>
using namespace std;
#define int long long

int LOG = 20;
vector<vector<int>> adj;
vector<vector<int>> dp_bin;
vector<int> parent; // changed from map to vector

void dfs(int node, vector<vector<int>> &adj, int parentNode, vector<int> &level, int l, vector<int> &depth, int d) {
    depth[node] = d;
    parent[node] = parentNode;  // store parent
    dp_bin[node][0] = parentNode; // base case for binary lifting

    // Precompute 2^i-th ancestors
    for (int i = 1; i < LOG; i++) {
        if (dp_bin[node][i - 1] != -1) {
            dp_bin[node][i] = dp_bin[dp_bin[node][i - 1]][i - 1];
        } else {
            dp_bin[node][i] = -1;
        }
    }

    level[node] = l;

    for (auto child : adj[node]) {
        if (child == parentNode) continue;
        dfs(child, adj, node, level, l + 1, depth, d + 1);
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); // ✅ speeds up output

    int n, q;
    cin >> n >> q;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    dp_bin.assign(n + 1, vector<int>(LOG, -1));
    vector<int> level(n + 1), depth(n + 1);
    parent.assign(n + 1, -1); // ✅ init vector

    // start DFS with l = 0 and d = 0
    dfs(1, adj, -1, level, 0, depth, 0);

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << depth[a] + depth[b] - 2 * depth[lca(a, b, level)] << "\n";
    }
}
