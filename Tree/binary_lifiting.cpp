#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF (LLONG_MAX >> 1)
const int MOD = 1e9 + 7;

const int LOG = 20; // log2(1e5) ≈ 17, safe margin
vector<vector<int>> dp_bin; // dp_bin[v][j] = 2^j-th ancestor
vector<vector<long long>> sumUp; // sumUp[v][j] = sum of values along 2^j jump
map<int,int> parent_map;    // For brute-force parent queries
vector<int> node_val;       // value at each node

// DFS to fill parent_map, levels, and dp_bin for binary lifting
void dfs(int node, vector<vector<int>> &adj, int parent, vector<int> &level, int l = 0) {
    parent_map[node] = parent;
    dp_bin[node][0] = parent; // base case for binary lifting
    sumUp[node][0] = (parent == -1 ? 0 : node_val[parent]); // sum when jumping 1 step up

    // Precompute 2^i-th ancestors and sums
    for (int i = 1; i < LOG; i++) {
        if (dp_bin[node][i - 1] != -1) {
            dp_bin[node][i] = dp_bin[dp_bin[node][i - 1]][i - 1];
            sumUp[node][i] = sumUp[node][i - 1] + sumUp[dp_bin[node][i - 1]][i - 1];
        } else {
            dp_bin[node][i] = -1;
            sumUp[node][i] = sumUp[node][i - 1];
        }
    }

    level[node] = l;

    for (auto child : adj[node]) {
        if (child == parent) continue;
        dfs(child, adj, node, level, l + 1);
    }
}

// Brute force kth parent (O(k))
void k_parent_brute(int node, int k) {
    int par = node;
    while (k-- && par != -1) {
        par = parent_map[par];
    }
    cout << par << endl;
}

// O(log n) kth parent using binary lifting
int kth_parent_binary(int node, int k) {
    for (int i = 0; i < LOG; i++) {
        if ((k >> i) & 1LL) {
            node = dp_bin[node][i];
            if (node == -1) break;
        }
    }
    return node;
}

// LCA using binary lifting
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

// Brute force LCA: find path to root for each node, then find first common
int lca_brute(int a, int b) {
    vector<int> path_a, path_b;

    // Get path from a to root
    while (a != -1) {
        path_a.push_back(a);
        a = parent_map[a];
    }

    // Get path from b to root
    while (b != -1) {
        path_b.push_back(b);
        b = parent_map[b];
    }

    // Reverse paths to start from root
    reverse(path_a.begin(), path_a.end());
    reverse(path_b.begin(), path_b.end());

    // Find first common node
    int lca_node = -1;
    for (size_t i = 0; i < min(path_a.size(), path_b.size()); i++) {
        if (path_a[i] == path_b[i])
            lca_node = path_a[i];
        else
            break;
    }

    return lca_node;
}

// NEW: compute path sum from root to a node
long long path_sum_to_root(int v) {
    long long ans = node_val[v];
    for (int j = LOG - 1; j >= 0; j--) {
        if (dp_bin[v][j] != -1) {
            ans += sumUp[v][j];
            v = dp_bin[v][j];
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, start_node;
    cin >> n >> k >> start_node; // n = nodes, k = kth parent query, start_node = starting node

    node_val.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> node_val[i]; // read values for nodes

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp_bin.assign(n + 1, vector<int>(LOG, -1));
    sumUp.assign(n + 1, vector<long long>(LOG, 0));
    vector<int> level(n + 1);

    // Preprocessing DFS
    dfs(1, adj, -1, level);

    // Brute force kth parent (single example)
    k_parent_brute(start_node, k);

    // Multiple queries for kth parent using binary lifting
    int q;
    cin >> q;
    while (q--) {
        int node, kk;
        cin >> node >> kk;
        cout << kth_parent_binary(node, kk) << endl;
    }

    // Multiple queries for LCA
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b, level) << endl;
    }

    // Single example for brute-force LCA
    int a, b;
    cin >> a >> b; // read two nodes
    cout << lca_brute(a, b) << endl;

    // Example queries for root-to-node path sums
    cin >> q;
    while (q--) {
        int node;
        cin >> node;
        cout << path_sum_to_root(node) << endl;
    }

    return 0;
}
